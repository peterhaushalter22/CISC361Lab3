#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include "sh.h"

void list(char **arguments){
    printf("Executing built-in list\n");

    char directoryName[MAXLINE];
    DIR *directory;
    struct dirent *d;

    for(int index = 0; arguments[index] != NULL; index++)
        printf("arguments[%d]: %s\n",  index,  arguments[index]);

    for(int index = 1; arguments[index] != NULL; index++){
        printf("arguments[%d]: %s",  index,  arguments[index]);

        if(arguments[index][0] != '/'){
            strcpy(directoryName, "/");
        }

        strcat(directoryName, arguments[index]);
        printf(("%s\n"), directoryName);

        directory = opendir(directoryName);

        if(directory == NULL && arguments[index] != NULL){
            printf("Directory not found\n");
            return;
        }else{

            d = readdir(directory);
            while(d != NULL){
                printf("a: %s\n", d->d_name);
                d = readdir(directory);
            }
        }

        printf("\n");
    }

    if(arguments[1] == NULL){
        directory = opendir(getcwd(NULL, 0));

        d = readdir(directory);
        while(d != NULL){
            printf("a: %s\n", d->d_name);
            d = readdir(directory);
        }
    }

    closedir(directory);

}

