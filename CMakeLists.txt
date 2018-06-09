cmake_minimum_required(VERSION 3.10)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled main.cpp lexer/Lexer.cpp lexer/Lexer.h lexer/Token.cpp lexer/Token.h parser/ast/Node.cpp parser/ast/Node.h parser/Parser.cpp parser/Parser.h Memory.cpp Memory.h Symbol.cpp Symbol.h)