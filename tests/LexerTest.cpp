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

BOOST_AUTO_TEST_CASE( statementWithStream ){

        Lexer lexer("pwd > a.txt");

        BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::IDENTIFIER);
        BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::STREAM);
        BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::STRING);
        BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::END);
}

BOOST_AUTO_TEST_CASE( statementWithPipes ){

        Lexer lexer("a | b | c");

        BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::IDENTIFIER);
        BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::PIPE);
        BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::IDENTIFIER);
        BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::PIPE);
        BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::IDENTIFIER);
        BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::END);
}

BOOST_AUTO_TEST_CASE( statementWithReversedQuotes ){

        Lexer lexer("`pwd`");

        BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::QUOTE_REVERSED);
        BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::IDENTIFIER);
        BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::QUOTE_REVERSED);
        BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::END);
}

BOOST_AUTO_TEST_CASE( assignmentStatement ){

            Lexer lexer("a=2");
            BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::IDENTIFIER);
            BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::EQ);
            BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::IDENTIFIER);
            BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::END);
}

BOOST_AUTO_TEST_CASE( iNeedADollarDollar ){

        Lexer lexer("pwd $a");
        BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::IDENTIFIER);
        BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::DOLLARSIGN);
        BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::IDENTIFIER);
        BOOST_CHECK(lexer.getNextToken().getType() == Token::TokenType::END);
}

BOOST_AUTO_TEST_SUITE_END()