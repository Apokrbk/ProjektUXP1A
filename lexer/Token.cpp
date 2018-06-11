//
// Created by apok on 04.06.18.
//

#include "Token.h"
#include "../parser/ast/Node.h"

Token::Token(Token::TokenType tokenType, std::string tokenData): tokenData(tokenData), tokenType(tokenType) {
}

std::string Token::getRepr() {
    std::string token;
    switch (tokenType)
        {
            case TokenType::IDENTIFIER:
                token = "IDENTIFIER";
                break;
            case TokenType::PIPE:
                token = "PIPE";
                break;
            case TokenType::KEYWORD:
                token = "KEYWORD";
                break;
            case TokenType::END:
                token = "END";
                break;
            case TokenType::EQ:
                token = "EQ";
                break;
            case TokenType::NUMBER:
                token = "NUMBER";
                break;
            case TokenType::SEMICOLON:
                token = "SEMICOLON";
                break;
            case TokenType::STREAM:
                token = "STREAM";
                break;
            case TokenType::PWD:
                token = "PWD";
                break;
            case TokenType::STRING:
                token = "STRING";
                break;
            default:
                token = "UNKNOWN";
        }

        return "<" + token + " token, content: " + tokenData + ">";
}

Token::TokenType Token::getType() {
    return tokenType;
}
