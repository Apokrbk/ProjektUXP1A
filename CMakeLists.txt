cmake_minimum_required(VERSION 3.5.1)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
#TODO sudo apt-get install libboost-all-dev
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIR})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/builtins)


add_executable(lexerTest tests/LexerTest.cpp lexer/Lexer.cpp lexer/Lexer.h lexer/Token.cpp lexer/Token.h)

add_executable(parserTest tests/ParserTest.cpp lexer/Lexer.cpp lexer/Lexer.h lexer/Token.cpp lexer/Token.h parser/ast/Node.cpp parser/ast/Node.h parser/Parser.cpp parser/Parser.h Memory.cpp Memory.h Symbol.cpp Symbol.h parser/ast/BinaryOpNode.cpp parser/ast/ExportNode.cpp parser/ast/FilenameNode.cpp parser/ast/NameNode.cpp parser/ast/ProgramCallNode.cpp parser/ast/QuotedNode.cpp parser/ast/VarIdNode.cpp parser/ast/VarNode.cpp parser/ast/SubstitutionNode.cpp exception/ParserException.cpp exception/ParserException.h exception/CommandNotFoundException.cpp exception/CommandNotFoundException.h)


add_executable(untitled main.cpp lexer/Lexer.cpp lexer/Lexer.h lexer/Token.cpp lexer/Token.h parser/ast/Node.cpp parser/ast/Node.h parser/Parser.cpp parser/Parser.h Memory.cpp Memory.h Symbol.cpp Symbol.h parser/ast/BinaryOpNode.cpp parser/ast/ExportNode.cpp parser/ast/FilenameNode.cpp parser/ast/NameNode.cpp parser/ast/ProgramCallNode.cpp parser/ast/QuotedNode.cpp parser/ast/VarIdNode.cpp parser/ast/VarNode.cpp parser/ast/SubstitutionNode.cpp exception/ParserException.cpp exception/ParserException.h exception/CommandNotFoundException.cpp exception/CommandNotFoundException.h)

add_executable(addHi builtins/addHi.cpp)

add_executable(echo builtins/echo.cpp)

add_executable(ls builtins/ls.cpp)

add_executable(rm builtins/rm.cpp)

add_executable(touch builtins/touch.cpp)

add_executable(pwd builtins/pwd.cpp)

