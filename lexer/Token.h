#ifndef UNTITLED_TOKEN_H
#define UNTITLED_TOKEN_H


#include <string>

class Token {
public:
    enum TokenType {
        SEMICOLON, PIPE, STREAM, EQ, END, NUMBER, IDENTIFIER, QUOTE_REVERSED, EXPORT, STRING, DOLLARSIGN,
        QUOTE
    };

    Token(TokenType tokenType, std::string tokenData);

    std::string getRepr();

    TokenType getType();
    std::string getTokenData();

private:
    TokenType tokenType;
    std::string tokenData;
};

std::string getTypeString(Token::TokenType type);

#endif //UNTITLED_TOKEN_H
