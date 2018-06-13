//
// Created by apok on 13.06.18.
//

#define BOOST_TEST_MODULE PARSER_TEST
#include <boost/test/included/unit_test.hpp>
#include <exception>
#include "../lexer/Lexer.h"
#include "../parser/Parser.h"

BOOST_AUTO_TEST_SUITE(PARSER_TEST_SUITE)
    BOOST_AUTO_TEST_CASE(pwd_test){

        Lexer lexer("pwd");
        Parser parser(lexer);
        auto ast = parser.parseStatement();
        BOOST_CHECK(ast->toString()=="<ProgramCallNode <NameNode <IDENTIFIER token, content: pwd>> ARGS: >");
    }

    BOOST_AUTO_TEST_CASE(cd_with_argument_test){

        Lexer lexer("cd Desktop");
        Parser parser(lexer);
        auto ast = parser.parseStatement();
        BOOST_CHECK(ast->toString()=="<ProgramCallNode <NameNode <IDENTIFIER token, content: cd>> ARGS: <NameNode <IDENTIFIER token, content: Desktop>>>");
    }

    BOOST_AUTO_TEST_CASE(simple_compound_statement){

        Lexer lexer("abc | abd");
        Parser parser(lexer);
        auto ast = parser.parseStatement();
        BOOST_CHECK(ast->toString()=="<BinaryOpNode: <ProgramCallNode <NameNode <IDENTIFIER token, content: abc>> ARGS: > <PIPE token, content: |> <ProgramCallNode <NameNode <IDENTIFIER token, content: abd>> ARGS: >>");
    }

    BOOST_AUTO_TEST_CASE(compound_statement_with_3_prog){

        Lexer lexer("a | b | c");
        Parser parser(lexer);
        auto ast = parser.parseStatement();
        BOOST_CHECK(ast->toString()=="<BinaryOpNode: <ProgramCallNode <NameNode <IDENTIFIER token, content: a>> ARGS: > <PIPE token, content: |> <BinaryOpNode: <ProgramCallNode <NameNode <IDENTIFIER token, content: b>> ARGS: > <PIPE token, content: |> <ProgramCallNode <NameNode <IDENTIFIER token, content: c>> ARGS: >>>");
    }

    BOOST_AUTO_TEST_CASE(assignment){

        Lexer lexer("a=5");
        Parser parser(lexer);
        auto ast = parser.parseStatement();
        BOOST_CHECK(ast->toString()=="<BinaryOpNode: <VarIdNode: <IDENTIFIER token, content: a>> <EQ token, content: => <NameNode <IDENTIFIER token, content: 5>>>");
    }

    BOOST_AUTO_TEST_CASE(empty_input){

        Lexer lexer("");
        Parser parser(lexer);
        auto ast = parser.parseStatement();
        BOOST_CHECK(ast==nullptr);
    }

    BOOST_AUTO_TEST_CASE(reversed_quotes){

        Lexer lexer("`abc`");
        Parser parser(lexer);
        auto ast = parser.parseStatement();
        BOOST_CHECK(ast->toString()=="<SubstitutionNode <ProgramCallNode <NameNode <IDENTIFIER token, content: abc>> ARGS: >>");
    }

    BOOST_AUTO_TEST_CASE(redirect_to_file){

        Lexer lexer("abc > plik.txt");
        Parser parser(lexer);
        auto ast = parser.parseStatement();
        std::cout<<ast->toString()<<std::endl;
        BOOST_CHECK(ast->toString()=="<BinaryOpNode: <ProgramCallNode <NameNode <IDENTIFIER token, content: abc>> ARGS: > <STREAM token, content: >> <FilenameNode <STRING token, content: plik.txt>>>");
    }

BOOST_AUTO_TEST_SUITE_END()