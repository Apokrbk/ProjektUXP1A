#ifndef UNTITLED_COMMANDNOTFOUNDEXCEPTION_H
#define UNTITLED_COMMANDNOTFOUNDEXCEPTION_H


#include <stdexcept>

class CommandNotFoundException: public std::runtime_error{

private:
    std::string msg;
public:

    CommandNotFoundException(const std::string &command);
    virtual const char* what();

};


#endif //UNTITLED_COMMANDNOTFOUNDEXCEPTION_H
