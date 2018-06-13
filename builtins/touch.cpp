//
// Created by kacper on 14.06.18.
//

#include <dirent.h>
#include <unistd.h>
#include <iostream>
#include <fstream>

void touch(std::string path){
    std::ofstream outfile;
    outfile.open(path.c_str());
    outfile.close();
}

int main(int argc, char *argv[]){
    touch(argv[0]);
}