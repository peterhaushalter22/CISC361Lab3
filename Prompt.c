#include <stdlib.h>
#include "sh.h"
void prompt (char * prompt, char buf){
    printf("Executive built-in prompt\n");
    if(strcmp(prompt, "") == 0){
        printf("input prompt prefix: ");
        fgets(buf, MAXLINE, stdin);

    }
}