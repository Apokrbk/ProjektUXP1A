//
// Created by marcin on 05.06.18.
//

#include "Memory.h"

Memory::Memory() {

}

std::string Memory::getParameter(int number) {
    return parameters[number - 1];
}

std::string Memory::putParameter(int number, std::string value) {
    return parameters[number - 1] = value;
}

std::string Memory::getCurrentName() {
    return currentName;
}

int Memory::getReturnCode() {
    return returnCode;
}

int Memory::getCurrentPID() {
    return currentPID;
}

int Memory::getArgumentsNumber() {
    return argumentsNumber;
}

std::vector<std::string> Memory::getPath() {
    return std::vector<std::string>(path);
}

std::string Memory::getHome() {
    return home;
}

std::string Memory::getUser() {
    return user;
}

int Memory::getUid() {
    return uid;
}

std::string Memory::getShell() {
    return shell;
}

std::string Memory::getTerm() {
    return term;
}

std::string Memory::getPwd() {
    return pwd;
}

std::string Memory::getOldpwd() {
    return oldpwd;
}

Symbol Memory::getSymbol(std::string name) {
    if (symbolTable.find(name) == symbolTable.end()) {
        return nullptr;
    } else {
        return symbolTable[name];
    }
}

void Memory::putSymbol(std::string name, Symbol symbol) {
    symbolTable[name] = symbol;
}

