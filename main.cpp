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
        std::cout<< memory.getPwd()<<"$";
        try {
            std::string command;
            std::getline(std::cin, command);
            auto lexer = Lexer(command);
            auto parser = Parser(lexer);
            auto ast = parser.parseStatement();
            while (ast != nullptr) {
                //std::cout << ast->toString() << std::endl;
                std::string result = ast->execute(&memory);
                if (result.length() > 0) {
                    lexer = Lexer(result);
                    auto lexer2 = Lexer(result);
                    auto parser2 = Parser(lexer);
                    auto ast2 = parser2.parseStatement();
                    ast2->execute(&memory);
                }
                ast = parser.parseStatement();
            }
        } catch (ParserException &e){
            std::cout << e.what() << std::endl;
        } catch (CommandNotFoundException &e){
            std::cout << e.what() << std::endl;
        }
    }
}