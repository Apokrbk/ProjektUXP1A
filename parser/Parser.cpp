//
// Created by marcin on 05.06.18.
//

#include <vector>
#include "Parser.h"
#include "ast/SubstitutionNode.h"
#include "ast/QuotedNode.h"
#include "ast/BinaryOpNode.h"
#include "ast/ExportNode.h"
#include "ast/NameNode.h"
#include "ast/VarNode.h"
#include "ast/VarIdNode.h"
#include "ast/FilenameNode.h"
#include "ast/ProgramCallNode.h"


Parser::Parser(Lexer& lexer): lexer(lexer), currentToken(this->lexer.getNextToken()){
}


void Parser::eat(Token::TokenType type) {
    if (currentToken.getType() != type)
        throw std::runtime_error("Syntax error in eat");
    currentToken = lexer.getNextToken();
}

void Parser::eat() {
    currentToken = lexer.getNextToken();
}

std::shared_ptr<Node> Parser::parseStatement() {
    std::shared_ptr<Node> node;
    if(currentToken.getType() == Token::TokenType::END)
        return nullptr;

    node = parseSubstitution();
    if (node != nullptr)
        return node;

    node = parseShellStatement();
    if (node != nullptr)
        return node;

    return node;
}

std::shared_ptr<Node> Parser::parseSubstitution() {
    std::shared_ptr<Node> node;
    if (currentToken.getType() != Token::TokenType::QUOTE_REVERSED)
        return node;

    eat(Token::TokenType::QUOTE_REVERSED);
    node = parseStatement();
    eat(Token::TokenType::QUOTE_REVERSED);

    return node;
}

std::shared_ptr<Node> Parser::parseShellStatement() {
    std::shared_ptr<Node> node;

    node = parseBasicStatement();
    if (node != nullptr)
        return node;

    node = parseCompoundStatement();
    if (node != nullptr)
        return node;

    node = parseExportStatement();
    if (node != nullptr)
        return node;

    return node;
}

std::shared_ptr<Node> Parser::parseBasicStatement() {
    std::shared_ptr<Node> node;

    node = parseQuotedStatement();
    if (node != nullptr)
        return node;

    node = parseNameStatement();
    if (node != nullptr)
        return node;

    node = parseVar();
    if (node != nullptr)
        return node;


    return node;

}

std::shared_ptr<Node> Parser::parseCompoundStatement() {
    std::shared_ptr<Node> node;
    Token token = currentToken;
    if(currentToken.getType()==Token::TokenType::STRING)
        eat(Token::TokenType::STRING);
    else
        eat(Token::TokenType::IDENTIFIER);
    node = parseProgramCall(std::static_pointer_cast<Node>(std::make_shared<NameNode>(token)));
    if (node == nullptr)
        return node;

    while(currentToken.getType() == Token::TokenType::PIPE || currentToken.getType() == Token::TokenType::STREAM){
        if(currentToken.getType() == Token::TokenType::PIPE){
            Token tokenOp = currentToken;
            eat(Token::TokenType::PIPE);
            node = std::static_pointer_cast<Node>(std::make_shared<BinaryOpNode>(node, tokenOp, parseCompoundStatement()));
        } else {
            Token tokenOp = currentToken;
            eat(Token::TokenType::STREAM);
            node = std::static_pointer_cast<Node>(std::make_shared<BinaryOpNode>(node, tokenOp, parseFileName()));
        }
    }

    return node;

}

std::shared_ptr<Node> Parser::parseExportStatement() {
    std::shared_ptr<Node> node;
    if(currentToken.getType() != Token::TokenType::EXPORT)
        return node;
    eat(Token::TokenType::EXPORT);
    Token token = currentToken;
    node = parseVarId();
    if(node == nullptr)
        throw std::runtime_error("Syntax error in parse export statement");

    return std::static_pointer_cast<Node>(std::make_shared<ExportNode>(token));
}

std::shared_ptr<Node> Parser::parseVarId() {
    std::shared_ptr<Node> node;
    if(currentToken.getType() != Token::TokenType::IDENTIFIER)
        return node;
    eat(Token::TokenType::IDENTIFIER);
    Token token = currentToken;
    return std::static_pointer_cast<Node>(std::make_shared<VarIdNode>(token));
}


std::shared_ptr<Node> Parser::parseVar() {
    std::shared_ptr<Node> node;
    if(currentToken.getType() != Token::TokenType::DOLLARSIGN)
        return node;
    eat(Token::TokenType::DOLLARSIGN);
    if(currentToken.getType() != Token::TokenType::IDENTIFIER)
        return node;
    eat(Token::TokenType::IDENTIFIER);
    Token token = currentToken;
    return std::static_pointer_cast<Node>(std::make_shared<VarNode>(token));
}

std::shared_ptr<Node> Parser::parseVarAssign(std::shared_ptr<Node> toBeAssigned) {
    Token op = currentToken;
    eat(Token::TokenType::EQ);
    if(currentToken.getType() == Token::TokenType::STRING || currentToken.getType() == Token::TokenType::IDENTIFIER){
        Token token = currentToken;
        eat();
        return std::static_pointer_cast<Node>(std::make_shared<BinaryOpNode>(toBeAssigned, op, std::make_shared<NameNode>(token)));
    }
    else{
        throw std::runtime_error("Syntax error in parsevarassign");
    }

}

std::shared_ptr<Node> Parser::parseFileName() {
    std::shared_ptr<Node> node;
    if(currentToken.getType() != Token::TokenType::STRING && currentToken.getType() != Token::TokenType::IDENTIFIER)
        return node;
    Token token = currentToken;
    eat();
    return std::static_pointer_cast<Node>(std::make_shared<FilenameNode>(token));
}

std::shared_ptr<Node> Parser::parseNameStatement() {
    if(currentToken.getType() == Token::TokenType::STRING){
        Token token = currentToken;
        eat(Token::TokenType::STRING);
        return parseCompoundStatement(std::static_pointer_cast<Node>(std::make_shared<NameNode>(token)));
    }

    if(currentToken.getType() == Token::TokenType::IDENTIFIER){
        Token token = currentToken;
        eat(Token::TokenType::IDENTIFIER);
        if(currentToken.getType() == Token::TokenType::EQ)
            return parseVarAssign(std::static_pointer_cast<Node>(std::make_shared<VarIdNode>(token)));
        else
            return parseCompoundStatement(std::static_pointer_cast<Node>(std::make_shared<NameNode>(token)));
    }
}

std::shared_ptr<Node> Parser::parseProgramCall(std::shared_ptr<Node> progname) {

    std::vector<std::shared_ptr<Node>> args;
    while(currentToken.getType() != Token::TokenType::PIPE && currentToken.getType() != Token::TokenType::STREAM && currentToken.getType() != Token::TokenType::END && currentToken.getType()!=Token::TokenType::QUOTE_REVERSED){
        if(currentToken.getType() == Token::TokenType::DOLLARSIGN){
            args.push_back(parseVar());
        }
        else if(currentToken.getType() == Token::TokenType::STRING || currentToken.getType() == Token::TokenType::IDENTIFIER){
            args.push_back(parseName());
            eat();
        }
        else{
            throw std::runtime_error("Syntax error in parseprogramcall");
        }
    }
    return std::static_pointer_cast<Node>(std::make_shared<ProgramCallNode>(progname, args));
}

std::shared_ptr<Node> Parser::parseName() {
    std::shared_ptr<Node> node;
    if(currentToken.getType() != Token::TokenType::STRING && currentToken.getType() != Token::TokenType::IDENTIFIER)
        return node;
    else{
        return std::static_pointer_cast<Node>(std::make_shared<NameNode>(currentToken));
    }


}

std::shared_ptr<Node> Parser::parseQuotedStatement() {
    std::shared_ptr<Node> node;
    if (currentToken.getType() != Token::TokenType::QUOTE)
        return node;

    eat(Token::TokenType::QUOTE);
    node = parseStatement();
    eat(Token::TokenType::QUOTE);

    return node;
}

std::shared_ptr<Node> Parser::parseCompoundStatement(std::shared_ptr<Node> progname) {
    std::shared_ptr<Node> node;
    node = parseProgramCall(progname);
    if (node == nullptr)
        return node;

    while(currentToken.getType() == Token::TokenType::PIPE || currentToken.getType() == Token::TokenType::STREAM){
        if(currentToken.getType() == Token::TokenType::PIPE){
            Token tokenOp = currentToken;
            eat(Token::TokenType::PIPE);
            node = std::static_pointer_cast<Node>(std::make_shared<BinaryOpNode>(node, tokenOp, parseCompoundStatement()));
        } else {
            Token tokenOp = currentToken;
            eat(Token::TokenType::STREAM);
            node = std::static_pointer_cast<Node>(std::make_shared<BinaryOpNode>(node, tokenOp, parseFileName()));
        }
    }

    return node;
}









