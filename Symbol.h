//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_SYMBOL_H
#define UNTITLED_SYMBOL_H


#include <string>

class Symbol {
public:
    Symbol(const std::string &value);

    const std::string &getValue() const;

    Symbol();

private:
    std::string value;
};


#endif //UNTITLED_SYMBOL_H
