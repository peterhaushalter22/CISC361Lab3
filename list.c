#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include "sh.h"

/*
    This function just lists the files in the current directory 
    or all the files in the directory listed.
    Input:
        char **arguments - argueemtns typd into the shell
    returns:
        void
*/
void list(char **arguments){
    printf("Executing built-in list\n");

    char directoryName[MAXLINE];
    DIR *directory; //defines DIR
    struct dirent *d; // defines dirent pointer

    for(int index = 0; arguments[index] != NULL; index++) // print
        printf("arguments[%d]: %s\n",  index,  arguments[index]); 

    for(int index = 1; arguments[index] != NULL; index++){
        printf("arguments[%d]: %s",  index,  arguments[index]);

        if(arguments[index][0] != '/'){ //checks if there is a / character
            strcpy(directoryName, "/");  //concatinates / and the name
        }

        strcat(directoryName, arguments[index]); //concatinates directory name onto string
        printf(("%s\n"), directoryName);

        directory = opendir(directoryName); // sets directory

        if(directory == NULL && arguments[index] != NULL){ //checks if directory was found
            perror("Directory not found\n");
            return;
        }else{

            //prints all of the files in the directory.
            d = readdir(directory); 
            while(d != NULL){
                printf("a: %s\n", d->d_name);
                d = readdir(directory);
            }
        }

        printf("\n");
    }

    //just prints lists all of the files in the current directory if the second argumnt is null.
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

