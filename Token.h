//
// Created by apok on 04.06.18.
//

#ifndef UNTITLED_TOKEN_H
#define UNTITLED_TOKEN_H


#include <string>

class Token {
public:
    enum TokenType {
        SEMICOLON, PIPE, STREAM, EQ, END, NUMBER, IDENTIFIER, KEYWORD
    };
    TokenType tokenType;
    std::string tokenData;
    Token(TokenType tokenType, std::string tokenData);
};


#endif //UNTITLED_TOKEN_H
