#include "sh.h"
#include <unistd.h>

int pipeCommand(char **arguments){

    // int index = 0;
    // while (arguments[index] != NULL){
    //     if (strcmp(arguments[index], "|&") == 0){
    //         //normalPipe(arguments[0]);

    //         pipe(fd);

    //         pid = fork();

    //         if (pid < 0){
    //             perror("fork error");
    //         }else if (pid == 0){
    //             //child

    //             close(1);
    //             dup(fd[1]);

    //             execvp(arguments[0], arguments[0]);
    //             perror("couldn't execute command");
    //             exit(127);
    //         }

    //         break;
    //     }else if (strcmp(arguments[1], "|") == 0){
    //         pipe(fd);

    //         pid = fork();

    //         if (pid < 0){
    //             perror("fork error");
    //         }else if (pid == 0){
    //             //child

    //             close(1);
    //             dup(fd[1]);

    //             execvp(arguments[0], arguments[0]);
    //             perror("couldn't execute command");
    //             exit(127);
    //         }

    //         //pipeWithError(arguments[0]);
    //         break;
    //     }

    //     index++;
    // }

    // return index;

    return 1;
}

void normalPipe(char *command)
{
    // pid = fork();
    // int fd[2];

    // if (pid < 0)
    // {
    //     perror("fork error");
    // }
    // else if (pid == 0)
    // {
    //     //child

    //     close(1);
    //     dup(fd[1]);

    //     execvp(command[0], command);
    //     perror("couldn't execute command");
    //     exit(127);
    // }
}

void pipeWithError(char *command)
{
    // pid = fork();
    // int fd[2];

    // if (pid < 0)
    // {
    //     perror("fork error");
    // }
    // else if (pid == 0)
    // {
    //     //child

    //     execvp(command[0], command);
    //     perror("couldn't execute command");
    //     exit(127);
    // }
}