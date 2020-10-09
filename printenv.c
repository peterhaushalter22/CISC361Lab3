#include  "sh.h"
/*
Description: This function returns nothing and takes in two char double pointers and an integer.
It is responsible for prrinting the environment of the current directory or given directories
*/
void printenv(char ** environment, int maxArguments, char ** arguments){
    int index = 0; 
    if(arguments[1] == NULL){ //checks that there are no arguments
        while(environment[index]){
            printf("%s\n", environment[index]); //prints envirronment of current directory through indexing
            index++;
        }

    }else if(arguments[2] != NULL){
        printf("%s\n", getenv(arguments[2])); //prints environment of the given directory
    }else{
        printf("Too many arguments\n"); // prints rror message if there are too msny arguments
    }
}