#include <unistd.h>  //included files and libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <glob.h>
#include <signal.h>
#include "sh.h"

#include<unistd.h> 

void background(const char * command,char *arguments){
	printf("In background: \n");
	int parent = getpid();
	int child;
	fork();
	if(parent != getpid()){
		printf("Child here");
		child = getpid();
		
		
		int status = execve(command,arguments, NULL);
		//execlp(command,arguments);
		printf("Status: %d\n",status);
        //kill(child,9);
		
	}
	
}
