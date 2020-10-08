#include "sh.h"
#include <stdlib.h>
#include <signal.h>

void killProc(char **arguments){
    printf("Executing built-in kill\n");

    int killSignal;

    if(arguments[1] == NULL){
        printf("Not enough arguments");
    }else if(arguments[1][0] == '-'){
       killSignal = atoi(&arguments[1][1]);
       printf("processKilled: %d, with signal: %d\n", atoi(arguments[2]), (int)killProc);
       kill(atoi(arguments[2]), killSignal);
    }else{
        printf("processKilled: %d", atoi(arguments[1]));
        kill(atoi(arguments[1]), SIGTERM);
    }
}