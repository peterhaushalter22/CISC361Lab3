#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <glob.h>
#include "sh.h"


int main(int argc, char **argv, char **envp){
	char	buffer[MAXLINE];
	char    *arguments[MAXARGS];
	char    *ptr;
	pid_t	pid;
	int	status;

	printf("[%s]>> ", getcwd(NULL, 0));
	while (fgets(buffer, MAXLINE, stdin) != NULL) {

		//continues if user just enters "\n".
		if (strlen(buffer) == 1 && buffer[strlen(buffer) - 1] == '\n')
		  goto nextprompt;

		if (buffer[strlen(buffer) - 1] == '\n'){
			buffer[strlen(buffer) - 1] = 0; 
		}

		int argumentIndex = 0;
		glob_t globPaths;
  		char **globOutput;
        char *token = strtok(buffer, " ");

        while (token != NULL && argumentIndex < MAXARGS){					   
			if (glob(token, 0, NULL, &globPaths) == 0) {
				for (globOutput = globPaths.gl_pathv; *globOutput != NULL; globOutput++){
					arguments[argumentIndex] = *globOutput;
					argumentIndex++;
				}
			}else{
				arguments[argumentIndex] = token;
				argumentIndex++;
			}

			token = strtok (NULL, " ");
        }

		arguments[argumentIndex] = (char *) NULL;

		// for(int index = 0; index < argumentIndex; index++){
		// 	printf("argumentIndex: %d, %s\n", index, arguments[index]);
		// }

		//continues if "blank" command.
		if (arguments[0] == NULL){
			goto nextprompt;
		}

		if (strcmp(arguments[0], "exit") == 0) {
			printf("You have exited the shell.\n");
			return 1;
		}else if (strcmp(arguments[0], "which") == 0) {
		  		struct pathelement *path, *tmp;
            	char *cmd;

				printf("Executing built-in [which]\n");

				//continues if no agruments are given to to which
		  		if (arguments[1] == NULL) {
		    		printf("which: Too few arguments.\n");
		    		goto nextprompt;
                }

		  		path = get_path();

                cmd = which(arguments[1], path);

                if (cmd) {
		    		printf("%s\n", cmd);
                    free(cmd);
                }else{
					printf("%s: Command not found\n", arguments[1]);
				}

		  		while (path) {
		     		tmp = path;
		     		path = path->next;
		     		free(tmp->element);
		     		free(tmp);
                }

		}else if(strcmp(arguments[0], "where") == 0){

			struct pathelement *path, *tmp;
            char **pathFound = NULL;

			printf("Executing built-in [where]\n");

			//continues if no agruments are given to to which
	  		if (arguments[1] == NULL) {	
				printf("where: Too few arguments.\n");
		    	goto nextprompt;
            }

			path = get_path();

            pathFound = where(arguments[1], path);

            if (pathFound){
                
				int index = 0;
				while(pathFound[index] != NULL) {
					printf("%s\n", pathFound[index]);
		 			free(pathFound[index]);
					index++;
            	}

				free(pathFound);

            }else{
				printf("%s: Command not found\n", arguments[1]);
			}

			while (path) {
				tmp = path;
		 		path = path->next;
		 		free(tmp->element);
		 		free(tmp);
            }

		}else if (strcmp(arguments[0], "pwd") == 0) {
			char    *workingDirectory;

			printf("Executing built-in [pwd]\n");
	        workingDirectory = getcwd(NULL, 0);
            printf("%s\n", workingDirectory);
            free(workingDirectory);
	    }else if(strcmp(arguments[0], "pid") == 0){
			printf("%d\n",getpid());
		}else if (strcmp(arguments[0], "printenv") == 0) {
<<<<<<< HEAD
			printenv(envp, argumentIndex, arguments);
		}else{

			struct pathelement *path, *tmp;
			char *cmd;

=======
			printenv(envp,arguments);
			
		}else if(strcmp(arguments[0], "setenv") == 0){
			if(arguments[1]== NULL){
			setenv(envp,arguments);
		}

		else{
>>>>>>> ef2a4e51ad1142993b1311c2a02fe726752b2644
			if((pid = fork()) < 0) {
				printf("fork error");
		  	}else if (pid == 0) {
				//execlp(arguments[0], buffer, NULL);

				path = get_path();
				cmd = which(arguments[0], path);
				execve(cmd, arguments, NULL);
				printf("couldn't execute: %s\n", arguments[0]);
				exit(127);
			}

		  /* parent */
			if ((pid = waitpid(pid, &status, 0)) < 0){
				printf("waitpid error");
			}

            // if (WIFEXITED(status)) S&R p. 239 
            //     printf("child terminates with (%d)\n", WEXITSTATUS(status));

			// while (path) {
			// 	tmp = path;
	     	// 	path = path->next;
	     	// 	free(tmp->element);
		 	// 	free(tmp);
            // }
        }

        nextprompt:
		globfree(&globPaths);
		printf("[%s]>> ", getcwd(NULL, 0));
	}

	exit(0);
}