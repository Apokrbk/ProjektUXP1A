//
// Created by marcin on 05.06.18.
//

#include "Memory.h"

const std::vector<std::string> &Memory::getParameters() const {
    return parameters;
}

const std::string &Memory::getCurrentName() const {
    return currentName;
}

int Memory::getReturnCode() const {
    return returnCode;
}

int Memory::getCurrentPID() const {
    return currentPID;
}

int Memory::getArgumentsNumber() const {
    return argumentsNumber;
}

const std::vector<std::string> &Memory::getPath() const {
    return path;
}

const std::string &Memory::getHome() const {
    return home;
}

const std::string &Memory::getUser() const {
    return user;
}

int Memory::getUid() const {
    return uid;
}

const std::string &Memory::getShell() const {
    return shell;
}

const std::string &Memory::getTerm() const {
    return term;
}

const std::string &Memory::getPwd() const {
    return pwd;
}

const std::string &Memory::getOldpwd() const {
    return oldpwd;
}
