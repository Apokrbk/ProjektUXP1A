//
// Created by kacper on 13.06.18.
//
#include <dirent.h>
#include <unistd.h>
#include <iostream>
#include <vector>

void echo(vector<char *>argv){
    std::string echo = "";
    for (int i = 0; i < argv.size(); ++i) {
        echo += argv[i] + " ";
    }
    std::cout << echo << std::endl;
}

int main(int argc, char *argv[]){
    echo(std::vector(argv));
}