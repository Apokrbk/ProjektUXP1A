//
// Created by chodi on 13.06.18.
//

#define BOOST_TEST_MODULE LEXER_TEST
#include <boost/test/included/unit_test.hpp>
#include <exception>
#include "../lexer/Lexer.h"

BOOST_AUTO_TEST_SUITE(LEXER_TEST_SUITE)
BOOST_AUTO_TEST_CASE( tokens ){

    Lexer lexer("pwd");

    BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::IDENTIFIER);
    BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::END);
}

BOOST_AUTO_TEST_SUITE_END()