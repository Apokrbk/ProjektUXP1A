#include <iostream>
#include "lexer/Lexer.h"
#include "parser/ast/Node.h"
#include "parser/Parser.h"

int main() {

    while(true) {
        std::string command;
        std::getline(std::cin, command);
        auto lexer = Lexer(command);
        auto parser = Parser(lexer);
        auto ast = parser.parseCommand();
        while (ast != nullptr) {
            std::cout << ast->toString()<< std::endl;
            ast->execute();
            ast = parser.parseCommand();
        }
    }
}