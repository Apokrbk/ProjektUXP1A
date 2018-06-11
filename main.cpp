#include <iostream>
#include "lexer/Lexer.h"
#include "parser/ast/Node.h"
#include "parser/Parser.h"
#include "Memory.h"
#include "exception/ParserException.h"
#include "exception/CommandNotFoundException.h"

int main() {

    auto memory = Memory();
    while(true) {
        std::cout<< "$";
        try {
            std::string command;
            std::getline(std::cin, command);
            auto lexer = Lexer(command);
            auto parser = Parser(lexer);
            auto ast = parser.parseStatement();
            while (ast != nullptr) {
                std::cout << ast->toString() << std::endl;
                ast->execute(&memory);
                ast = parser.parseStatement();
            }
        } catch (ParserException &e){
            std::cout << e.what() << std::endl;
        } catch (CommandNotFoundException &e){
            std::cout << e.what() << std::endl;
        }
    }
}