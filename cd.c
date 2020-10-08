#include "sh.h"
#include <stdlib.h>

void cd (char *dir){
    char *oldwd = getcwd(NULL,0);
    if(strcmp(dir,"~") == 0 || dir == NULL){
        if(chdir(getenv("HOME")) != 0){
            perror("cd failed");
            return;
        }
    }else if(strcmp(dir,"-") == 0){
        if(chdir(getenv("OLDPWD"))!= 0){
            perror("cd failed"); 
            return;
        }
    }else{
        if(chdir(dir) != 0){
            perror("cd failed");
            return;
        }
    }

    if(setenv("OLDPWD", oldwd, 1) < 0){
            perror("cd failed");
        }

    if(setenv("PWD", getcwd(NULL,0), 1) < 0){
        perror("cd failed");  
    }
}