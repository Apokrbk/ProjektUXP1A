//
// Created by apok on 04.06.18.
//

#include "Token.h"

Token::Token(Token::TokenType tokenType, std::string tokenData) {
    this->tokenType=tokenType;
    this->tokenData=tokenData;
}
