//
// Created by kacper on 13.06.18.
//

#include <unistd.h>
#include <iostream>
#include <pwd.h>


void pwd(){
    uid_t uid = geteuid();
    struct passwd *structpasswd = getpwuid(uid);
    if(structpasswd)
        std::cout<<structpasswd->pw_dir<<std::endl;
}

int main(int argc, char *argv[]){
    pwd();
}
