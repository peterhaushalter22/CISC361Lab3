#include  "sh.h"

void printenv(char ** environment, int maxArguments, char ** arguments){
    int index = 0;
    if(arguments[1] == NULL){
        while(environment[index]){
            printf("%s\n", environment[index]);
            index++;
        }

    }else if(arguments[2] != NULL){
        printf("%s\n", getenv(arguments[2]));
    }
}