#include "Token.h"

Token::Token(Token::TokenType tokenType, std::string tokenData) : tokenData(tokenData), tokenType(tokenType) {
}

std::string getTypeString(Token::TokenType type) {
    std::string token;
    switch (type) {
        case Token::TokenType::IDENTIFIER:
            token = "IDENTIFIER";
            break;
        case Token::TokenType::PIPE:
            token = "PIPE";
            break;
        case Token::TokenType::QUOTE_REVERSED:
            token = "QUOTE_REVERSED";
            break;
        case Token::TokenType::END:
            token = "END";
            break;
        case Token::TokenType::EQ:
            token = "EQ";
            break;
        case Token::TokenType::NUMBER:
            token = "NUMBER";
            break;
        case Token::TokenType::SEMICOLON:
            token = "SEMICOLON";
            break;
        case Token::TokenType::STREAM:
            token = "STREAM";
            break;
        case Token::TokenType::EXPORT:
            token = "EXPORT";
            break;
        case Token::TokenType::STRING:
            token = "STRING";
            break;
        case Token::TokenType::DOLLARSIGN:
            token = "DOLLARSIGN";
            break;
        case Token::TokenType::QUOTE:
            token = "QUOTE";
            break;
        default:
            token = "UNKNOWN";
    }

    return token;
}



Token::TokenType Token::getType() {
    return tokenType;
}

std::string Token::getRepr() {
    return "<" + getTypeString(tokenType) + " token, content: " + tokenData + ">";
}