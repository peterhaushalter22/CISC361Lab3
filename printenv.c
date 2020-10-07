#include  "sh.h"

void printenv(char ** environment){
    
    if(environment == NULL){        
            return;
    }else if(environment != NULL){
        int index = 0;
        while(environment[index]){
            printf("%s\n", environment[index]);
            //printf("%s=%s\n", environment[index], getenv(environment[index]));
            index++;
        }

        return;
    }
    else{
        printf("ERROR");
        return;
    }
}