//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_SYMBOLTABLE_H
#define UNTITLED_SYMBOLTABLE_H


#include <string>
#include <vector>
#include <map>

class Memory {
private:
    std::map<std::string, Symbol>;

    std::vector<std::string> parameters;
    std::string currentName;
    int returnCode;
    int currentPID;
    int argumentsNumber;
    std::vector<std::string> path;
public:
    const std::vector<std::string> &getParameters() const;

    const std::string &getCurrentName() const;

    int getReturnCode() const;

    int getCurrentPID() const;

    int getArgumentsNumber() const;

    const std::vector<std::string> &getPath() const;

    const std::string &getHome() const;

    const std::string &getUser() const;

    int getUid() const;

    const std::string &getShell() const;

    const std::string &getTerm() const;

    const std::string &getPwd() const;

    const std::string &getOldpwd() const;

private:
    std::string home;
    std::string user;
    int uid;
    std::string shell;
    std::string term;
    std::string pwd;
    std::string oldpwd;
};


#endif //UNTITLED_SYMBOLTABLE_H
