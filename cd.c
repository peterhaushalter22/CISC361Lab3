#include "sh.h"
#include <stdlib.h>
/*
void cd (char *dir){
 char *old = "OLDPWD";
 char *oldwd = getcwd(NULL,0);
 printf("HERE");
 if(strcmp(dir,"") == 0){
     if(chdir(getenv("HOME"))< 0){
         perror("cd failed");
     }else if(strcmp(dir,"-") == 0){
         printf("%s\n", getenv("OLDPWD"));
         if(chdir(getenv("OLDPWD"))!= 0){
            perror("cd failed"); 
         }else{
             if(chdir(dir)<0){
                 perror("cd failed");
             }
         }
            char *new = "PWD";
            if(setenv(new, getcwd(NULL,0), 1) < 0){
                perror("cd failed");  
            }
            if(setenv(old, oldwd, 1) < 0){
                perror("cd failed");  
            }
     }
 }
}

*/