//
// Created by kacper on 13.06.18.
//

#include <unistd.h>
#include <iostream>
#include <pwd.h>


void pwd(std::string pwd){
    std::cout<<pwd<<std::endl;
}

int main(int argc, char *argv[]){
    pwd(argv[0]);
}
