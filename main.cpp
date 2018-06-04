#include <iostream>
#include "Lexer.h"

int main() {
    Lexer lexer = Lexer("aaa = 512 ff           cd pwd|;<> ");
    Token t = lexer.getNextToken();
    while(t.tokenType != Token::TokenType::END){
        std::cout << t.tokenType << "  " << t.tokenData << std::endl;
        t = lexer.getNextToken();
    }
}