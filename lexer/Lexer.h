#ifndef UNTITLED_LEXER_H
#define UNTITLED_LEXER_H


#include <string>
#include "Token.h"
#include <wctype.h>

class Lexer {

public:
    void advance();
    Token getNextToken();
    Lexer(std::string input);
private:
    char currentChar;
    int currentPos;
    std::string input;
    std::string tokenData;
};


#endif //UNTITLED_LEXER_H
