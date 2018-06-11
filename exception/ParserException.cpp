
#include "ParserException.h"

ParserException::ParserException():runtime_error("") {
    msg = "Invalid syntax";
}

ParserException::ParserException(const std::string &actual, const std::string &expected): runtime_error("") {
    msg = "Invalid syntax. Expected: " + expected + ", found: " + actual;
}

const char *ParserException::what(){
    return msg.c_str();
}
