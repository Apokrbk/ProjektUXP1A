#include <iostream>
#include "lexer/Lexer.h"
#include "parser/ast/Node.h"
#include "parser/Parser.h"

int main() {

    while(true) {
        try {
            std::string command;
            std::getline(std::cin, command);
            auto lexer = Lexer(command);
            auto parser = Parser(lexer);
            auto ast = parser.parseStatement();
            while (ast != nullptr) {
                std::cout << ast->toString() << std::endl;
                ast = parser.parseStatement();
            }
        } catch (std::runtime_error &e){
            std::cout << e.what() << std::endl;
        }
    }
}