//
// Created by kacper on 13.06.18.
//
#include <dirent.h>
#include <unistd.h>
#include <iostream>
#include <vector>

void echo(std::string arg){
    std::cout << arg;
}

int main(int argc, char *argv[]){
    echo(argv[0]);
}