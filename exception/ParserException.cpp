
#include <iostream>
#include "ParserException.h"

ParserException::ParserException():runtime_error("") {
    msg = "Invalid syntax.\n";
}

ParserException::ParserException(const std::string &expected, const std::string &actual): runtime_error("") {
    msg = "Invalid syntax. Expected: " + expected + ", found: " + actual + "\n";
}

const char *ParserException::what(){
    return msg.c_str();
}

