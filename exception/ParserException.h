#ifndef UNTITLED_PARSEREXCEPTION_H
#define UNTITLED_PARSEREXCEPTION_H


#include <stdexcept>

class ParserException: public std::runtime_error{

private:
    std::string msg;
public:

    ParserException();
    ParserException(const std::string &actual, const std::string &expected);
    virtual const char* what();

};


#endif //UNTITLED_PARSEREXCEPTION_H
