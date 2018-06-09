#ifndef UNTITLED_TOKEN_H
#define UNTITLED_TOKEN_H


#include <string>

class Token {
public:
    enum TokenType {
        SEMICOLON, PIPE, STREAM, EQ, END, NUMBER, IDENTIFIER, KEYWORD, PWD, QUOTE_REVERSED
    };
    Token(TokenType tokenType, std::string tokenData);

    std::string getRepr();

    TokenType getType();

private:
    TokenType tokenType;
    std::string tokenData;
};


#endif //UNTITLED_TOKEN_H
