//
// Created by kacper on 13.06.18.
//

#include <pwd.h>
#include <zconf.h>
#include <iostream>

void pwd(){
    uid_t uid = geteuid();
    struct passwd *structpasswd = getpwuid(uid);
    if(structpasswd)
        std::cout<<structpasswd->pw_dir<<std::endl;
}

int main(int argc, char *argv[]){
    pwd();
}
