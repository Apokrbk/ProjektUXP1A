#include "CommandNotFoundException.h"

CommandNotFoundException::CommandNotFoundException(const std::string &command) : std::runtime_error("") {
    msg = command;
}

const char *CommandNotFoundException::what(){
    return msg.c_str();
}