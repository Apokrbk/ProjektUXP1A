#include <cstdio>
#include <dirent.h>
#include <unistd.h>
#include <iostream>
#include <fstream>

void remove(std::string path){
    std::remove(path.c_str());
}

int main(int argc, char *argv[]){
    remove(argv[0]);
}