//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_SYMBOLTABLE_H
#define UNTITLED_SYMBOLTABLE_H


#include <string>
#include <vector>
#include <map>
#include "Symbol.h"

class Memory {
private:
    std::map<std::string, Symbol> symbolTable;
    std::vector<std::string> parameters;
    std::string currentName;
    int returnCode;
    int currentPID;
    int argumentsNumber;
    std::vector<std::string> path;

    std::string home;
    std::string user;
    int uid;
    std::string shell;
    std::string term;
    std::string pwd;
    std::string oldpwd;
    
public:
    Memory(); // TODO fill with env parameters
    std::string getParameter(int number);
    std::string putParameter(int number, std::string);
    std::string getCurrentName();
    int getReturnCode();
    int getCurrentPID();
    int getArgumentsNumber();
    std::vector<std::string> getPath();
    std::string getHome();
    std::string getUser();
    int getUid();
    std::string getShell();
    std::string getTerm();
    std::string getPwd();
    std::string getOldpwd();
    
    Symbol getSymbol(std::string);
    void putSymbol(std::string name, Symbol symbol);
};


#endif //UNTITLED_SYMBOLTABLE_H
