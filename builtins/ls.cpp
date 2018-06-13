//
// Created by kacper on 13.06.18.
//

#include <dirent.h>
#include <unistd.h>
#include <iostream>
#include <pwd.h>


void ls(std::string pwd){
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
    std::cout<<files;
}

int main(int argc, char *argv[]){
    ls(argv[0]);
}