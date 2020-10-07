#include  "sh.h"

<<<<<<< HEAD
void printenv(char ** environment, int maxArguments, char ** arguments){
    int index = 0;
    if(arguments[1] == NULL){
=======
void printenv(char ** environment, char *arguments){
    
    if(environment == NULL){ 
            printf("Environment null");       
            return;
    }else if(arguments[1]== NULL){
        int index = 0;
>>>>>>> ef2a4e51ad1142993b1311c2a02fe726752b2644
        while(environment[index]){
            printf("%s\n", environment[index]);
            index++;
        }

<<<<<<< HEAD
    }else if(arguments[1] != NULL){
        printf("%s\n", getenv(arguments[2]));
=======
        return;
    }
    else if(arguments[2]== NULL){
        getenv(3);
        return;
    }
    else{
        printf("ERROR");
        return;
>>>>>>> ef2a4e51ad1142993b1311c2a02fe726752b2644
    }
}