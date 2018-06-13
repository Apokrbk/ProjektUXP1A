cmake_minimum_required(VERSION 3.6.1)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp lexer/Lexer.cpp lexer/Lexer.h lexer/Token.cpp lexer/Token.h parser/ast/Node.cpp parser/ast/Node.h parser/Parser.cpp parser/Parser.h Memory.cpp Memory.h Symbol.cpp Symbol.h parser/ast/BinaryOpNode.cpp parser/ast/ExportNode.cpp parser/ast/FilenameNode.cpp parser/ast/NameNode.cpp parser/ast/ProgramCallNode.cpp parser/ast/QuotedNode.cpp parser/ast/VarIdNode.cpp parser/ast/VarNode.cpp parser/ast/SubstitutionNode.cpp exception/ParserException.cpp exception/ParserException.h exception/CommandNotFoundException.cpp exception/CommandNotFoundException.h)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/builtins)

add_executable(ls builtins/ls.cpp)

add_executable(pwd builtins/pwd.cpp)