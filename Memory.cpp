//
// Created by marcin on 05.06.18.
//

#include <unistd.h>
#include <pwd.h>
#include <dirent.h>
#include <sys/stat.h>
#include "Memory.h"

Memory::Memory() {
    initHome();
    pwd=home;
    oldpwd=getParentDirFromDir(pwd);
    putSymbol("PWD", Symbol(pwd));
    putSymbol("HOME", Symbol(home));
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
    Symbol symbol;
    if (symbolTable.find(name) == symbolTable.end()) {
        return symbol;
    } else {
        return symbolTable[name];
    }
}

void Memory::putSymbol(std::string name, Symbol symbol) {
    symbolTable[name] = symbol;
}

void Memory::initHome() {
    uid_t uid = geteuid();
    struct passwd *structpasswd = getpwuid(uid);
    if(structpasswd)
        home = structpasswd->pw_dir;
    else
        throw std::runtime_error("Error with init home path");
}

std::string Memory::getParentDirFromDir(std::string dir) {
    if(dir=="/")
        return dir;
    if(dir.find("/") != std::string::npos){
        unsigned long idx = dir.rfind("/");
        if(idx==0)
            return "/";
        else
            return dir.substr(0, idx);
    }
    else{
        throw std::runtime_error("Incorrect dir");
    }
}

std::string Memory::ls() {
    std::string files;
    DIR *d;
    struct dirent *dir;
    d = opendir(pwd.c_str());
    if(d) {
        while ((dir = readdir(d)) != nullptr) {
            if(dir->d_name[0] != '.'){
                files+=dir->d_name;
                files+="\n";
            }
        }
        closedir(d);
    }
    return files;
}

void Memory::cd(std::string path) {
    if(path=="."){

    }
    else if(path==".."){
        oldpwd=pwd;
        pwd=getParentDirFromDir(pwd);
    }
    else if(path==""){
        oldpwd=pwd;
        pwd=home;
    }
    else{

        struct stat sb;

        if (stat((pwd + "/" + path).c_str(), &sb) == 0 && S_ISDIR(sb.st_mode))
        {
            oldpwd=pwd;
            if(pwd!="/")
                pwd+="/";
            pwd+=path;
            putSymbol("PWD", Symbol(pwd));
            putSymbol("OLDPWD", Symbol(oldpwd));
        } else {
            throw std::runtime_error("Cannot access " + path);
        }
    }
}


