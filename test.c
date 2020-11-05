     
#include <unistd.h>  //included files and libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <glob.h>
#include <signal.h>
#include "sh.h"

void test(){
    printf("im here");
    int d = 0;
    int i = 0;
    while(1){
        i++;
        if(i>1000000000){
            printf("Child alive %d seconds\n", d);
            i = 0;
            d++;
            if(d > 15){
                break;
            }
        }
    }
}