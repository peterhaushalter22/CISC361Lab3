#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "sh.h"

int main(int argc, char **argv, char **envp){
	char	buffer[MAXLINE];
	char    *arguments[MAXARGS];
	char    *ptr;
    char    *token;
	pid_t	pid;
	int	status, argumentIndex;

	printf(">> ");
	while (fgets(buffer, MAXLINE, stdin) != NULL) {

		//continues if user just enters "\n".
		if (strlen(buffer) == 1 && buffer[strlen(buffer) - 1] == '\n')
		  goto nextprompt;

		if (buffer[strlen(buffer) - 1] == '\n'){
			buffer[strlen(buffer) - 1] = 0; 
		}

		argumentIndex = 0;
        token = strtok(buffer, " ");
        while (token != NULL && argumentIndex < MAXARGS){
	  		arguments[argumentIndex] = token;
	 		argumentIndex++;                
			token = strtok (NULL, " ");
        }

		arguments[argumentIndex] = (char *) NULL;

		//continues if "blank" command.
		if (arguments[0] == NULL){
			goto nextprompt;
		}


		/*
		//used to print arguments
		for (int index = 0; index < argumentIndex; index++){
			printf("arg[%d] = %s\n", index, arguments[index]);
		}
		//*/

        if (strcmp(arguments[0], "pwd") == 0) {
			char    *workingDirectory;

			printf("Executing built-in [pwd]\n");
	        workingDirectory = getcwd(NULL, 0);
            printf("%s\n", workingDirectory);
            free(workingDirectory);
	    }else if (strcmp(arguments[0], "which") == 0) {
		  		struct pathelement *p, *tmp;
            	char *cmd;

				printf("Executing built-in [which]\n");

				//continues if no agruments are given to to which
		  		if (arguments[1] == NULL) {
		    		printf("which: Too few arguments.\n");
		    		goto nextprompt;
                }

		  		p = get_path();

				/*
				//used to print argumetns in which
		  		tmp = p;
		  		while (tmp) {
		    		printf("path [%s]\n", tmp->element);
		    		tmp = tmp->next;
                }
				//*/

                cmd = which(arguments[1], p);

                if (cmd) {
		    		printf("%s\n", cmd);
                    free(cmd);
                }else{
					printf("%s: Command not found\n", arguments[1]);
				}

		  		while (p) {
		     		tmp = p;
		     		p = p->next;
		     		free(tmp->element);
		     		free(tmp);
                }

		}else{
			if((pid = fork()) < 0) {
				printf("fork error");
		  	}else if (pid == 0) {
				execlp(buffer, buffer, (char *)NULL);
				printf("couldn't execute: %s", buffer);
				exit(127);
			}

		  /* parent */
			if ((pid = waitpid(pid, &status, 0)) < 0){
				printf("waitpid error");
			}

            // if (WIFEXITED(status)) S&R p. 239 
            //     printf("child terminates with (%d)\n", WEXITSTATUS(status));
        }

        nextprompt:
		printf(">> ");
	}

	exit(0);
}