//
// Created by marcin on 05.06.18.
//

#include "Symbol.h"

Symbol::Symbol(const std::string &value) : value(value) {}

Symbol::Symbol() {}

const std::string &Symbol::getValue() const {
    return value;
}
