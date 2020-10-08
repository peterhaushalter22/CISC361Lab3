#include <stdlib.h>
#include "sh.h"
/*
void list(char **args){
    pathelement *direc;
    struct dirent *d;

    int i = 1;
    while(args[i] != NULL){
        char *adirec = calloc(MAXLINE,1);
        printf("args[i] %s\n" , args[i]);

        if(args[i][0] != '/'){
            strcpy(adirect, "/");
            
            strcat(adirec,args[i]);
            printf(("%s\n"),adirec);
            direc = opendir(adirec);
        }
        if(direc == NULL && args[i] != NULL){
            printf("directory not found\n");
            return;
        }else{
            while((d = readdir(direc)) != NULL){
                printf("a: %s\n", d->d_name);
            }
        }
        printf("\n");
        i++;
        free(adirec);
    }
    if(args[1]== NULL){
        direc = opendir(getcwd(NULL,0));
        while((d = readdir(direc)) != NULL){
            printf("%s\n", d-> d_name);
        }
    }
    closedir(direc);
}

*/