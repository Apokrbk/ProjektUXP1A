#include "CommandNotFoundException.h"

CommandNotFoundException::CommandNotFoundException(const std::string &command) : std::runtime_error("") {
    msg = "Command " + command + " not found.\n";
}

const char *CommandNotFoundException::what(){
    return msg.c_str();
}