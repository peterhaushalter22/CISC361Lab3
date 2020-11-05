#include <unistd.h> //included files and libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <glob.h>
#include <signal.h>
#include "sh.h"
#include <unistd.h>
#include <sys/types.h>
pid_t background(char **arguments, int argumentIndex)
{
	int * status = 0;

	printf("In background: \n");
	pid_t child = fork();
	if (child == 0)
	{
		struct pathelement *path = get_path();
		char *cmd = which(arguments[0], path);
		execve(cmd, arguments, NULL);
		execve(arguments[0], arguments, NULL);
		perror("Background Process Failed");
	}
	else{
		waitpid(-1, &status, 0);
	}
	return child;
}
