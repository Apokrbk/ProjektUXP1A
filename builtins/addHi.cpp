//
// Created by kacper on 13.06.18.
//
#include <dirent.h>
#include <unistd.h>
#include <iostream>
#include <string>

void addHi(){
    char readBuffer[2048];

    read(0, readBuffer, 2048);
    std::string s = std::string(readBuffer);
    if(s.back() == '\n')
        s.pop_back();
    s.append("Hi");
    std::cout<< s;
}

int main(int argc, char *argv[]){
    addHi();
}