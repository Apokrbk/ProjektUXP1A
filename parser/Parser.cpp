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
#include "../exception/ParserException.h"
#include "../exception/CommandNotFoundException.h"


Parser::Parser(Lexer& lexer): lexer(lexer), currentToken(this->lexer.getNextToken()){
}


void Parser::eat(Token::TokenType type) {
    /**
     * Eat current token and throw exception if it isn't of the given type
     */
    if (currentToken.getType() != type)
        throw ParserException(getTypeString(currentToken.getType()), getTypeString(type));
    currentToken = lexer.getNextToken();
}

std::shared_ptr<Node> Parser::parseStatement() {
    std::shared_ptr<Node> node;
    if(currentToken.getType() == Token::TokenType::END)
        return nullptr;

    node = parseShellStatement();
    if (node != nullptr)
        return node;

    if (currentToken.getType() != Token::TokenType::END)
        throw ParserException();

    return node;
}

std::shared_ptr<Node> Parser::parseSubstitution() {
    std::shared_ptr<Node> node;
    if (currentToken.getType() != Token::TokenType::QUOTE_REVERSED)
        return node;

    eat(Token::TokenType::QUOTE_REVERSED);
    node = parseStatement();
    eat(Token::TokenType::QUOTE_REVERSED);

    return std::static_pointer_cast<Node>(std::make_shared<SubstitutionNode>(node));
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
    if (currentToken.getType()==Token::TokenType::STRING ||
        currentToken.getType()==Token::TokenType::IDENTIFIER ||
        currentToken.getType()==Token::TokenType::QUOTE_REVERSED){
        if(currentToken.getType()==Token::TokenType::QUOTE_REVERSED){
            node = parseSubstitution();
        } else {
            if (currentToken.getType() == Token::TokenType::STRING)
                eat(Token::TokenType::STRING);
            else if (currentToken.getType() == Token::TokenType::IDENTIFIER)
                eat(Token::TokenType::IDENTIFIER);

            node = parseProgramCall(std::static_pointer_cast<Node>(std::make_shared<NameNode>(token)));
        }
        if (node == nullptr)
            return node;

        while(currentToken.getType() == Token::TokenType::PIPE || currentToken.getType() == Token::TokenType::STREAM) {
            if (currentToken.getType() == Token::TokenType::PIPE) {
                Token tokenOp = currentToken;
                eat(Token::TokenType::PIPE);
                node = std::static_pointer_cast<Node>(
                        std::make_shared<BinaryOpNode>(node, tokenOp, parseCompoundStatement()));
            } else {
                Token tokenOp = currentToken;
                eat(Token::TokenType::STREAM);
                node = std::static_pointer_cast<Node>(std::make_shared<BinaryOpNode>(node, tokenOp, parseFileName()));
            }
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
        throw ParserException(getTypeString(currentToken.getType()), "VARIABLE_ID");

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
        throw ParserException(getTypeString(Token::TokenType::IDENTIFIER), getTypeString(currentToken.getType()));
    Token token = currentToken;
    eat(Token::TokenType::IDENTIFIER);
    return std::static_pointer_cast<Node>(std::make_shared<VarNode>(token));
}

std::shared_ptr<Node> Parser::parseVarAssign(std::shared_ptr<Node> toBeAssigned) {
    Token op = currentToken;
    eat(Token::TokenType::EQ);
    if(currentToken.getType() == Token::TokenType::STRING || currentToken.getType() == Token::TokenType::IDENTIFIER){
        Token token = currentToken;
        if(currentToken.getType() == Token::TokenType::STRING)
            eat(Token::TokenType::STRING);
        else
            eat(Token::TokenType::IDENTIFIER);
        return std::static_pointer_cast<Node>(std::make_shared<BinaryOpNode>(toBeAssigned, op, std::make_shared<NameNode>(token)));
    }
    else{
        throw ParserException(getTypeString(currentToken.getType()), "VALUE");
    }

}

std::shared_ptr<Node> Parser::parseFileName() {
    std::shared_ptr<Node> node;
    if(currentToken.getType() != Token::TokenType::STRING && currentToken.getType() != Token::TokenType::IDENTIFIER)
        return node;
    Token token = currentToken;
    if(currentToken.getType() == currentToken.getType() != Token::TokenType::STRING)
        eat(Token::TokenType::STRING);
    else
        eat(Token::TokenType::IDENTIFIER);
    return std::static_pointer_cast<Node>(std::make_shared<FilenameNode>(token));
}

std::shared_ptr<Node> Parser::parseNameStatement() {
    std::shared_ptr<Node> node;
    if(currentToken.getType() == Token::TokenType::STRING){
        Token token = currentToken;
        eat(Token::TokenType::STRING);
        return parseCompoundStatement(std::static_pointer_cast<Node>(std::make_shared<NameNode>(token)));
    } else if(currentToken.getType() == Token::TokenType::IDENTIFIER){
        Token token = currentToken;
        eat(Token::TokenType::IDENTIFIER);
        if(currentToken.getType() == Token::TokenType::EQ)
            return parseVarAssign(std::static_pointer_cast<Node>(std::make_shared<VarIdNode>(token)));
        else
            return parseCompoundStatement(std::static_pointer_cast<Node>(std::make_shared<NameNode>(token)));
    } else{
        return node;
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
            if(currentToken.getType() == Token::TokenType::STRING)
                eat(Token::TokenType::STRING);
            else
                eat(Token::TokenType::IDENTIFIER);
        }
        else{
            throw ParserException(getTypeString(currentToken.getType()), "ARGS");
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









