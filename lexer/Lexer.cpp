#include <map>
#include "Lexer.h"


Lexer::Lexer(std::string input) {
    this->input = input;
    this->currentPos = 0;
    this->tokenData = "";
    this->currentChar = '\0';
}

void Lexer::advance() {
    if (currentPos > input.size()) {
        currentChar = '\0';
    } else {
        currentChar = input[currentPos];
        currentPos++;
    }
}

Token Lexer::getNextToken() {
    tokenData = "";
    advance();
    while (isspace(currentChar))
        advance();
    if (currentChar == '\0') {
        return Token(Token::TokenType::END, "");
    } else if (currentChar == '=') {
        return Token(Token::TokenType::EQ, "=");
    } else if (currentChar == ';') {
        return Token(Token::TokenType::SEMICOLON, ";");
    } else if (currentChar == '|') {
        return Token(Token::TokenType::PIPE, "|");
    } else if (currentChar == '<' || currentChar == '>') {
        return Token(Token::TokenType::STREAM, std::string(1, currentChar));
    }else if (currentChar == '`' ) {
        return Token(Token::TokenType::QUOTE_REVERSED,"`");
    }else if(currentChar == '$'){
        return Token(Token::TokenType::DOLLARSIGN, "$");
    }
    else {
        while (isalpha(currentChar) || isdigit(currentChar) || currentChar=='.') {
            tokenData += currentChar;
            advance();
        }
        currentPos--;

        if(!isalpha(tokenData[0]) || tokenData.find(".") != std::string::npos)
            return Token(Token::TokenType::STRING, tokenData);
        else
            return Token(Token::TokenType::IDENTIFIER, tokenData);
    }
}
