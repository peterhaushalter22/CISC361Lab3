#include "get_path.h"

int pid;
char *which(char *command, struct pathelement *pathlist);
char **where(char *command, struct pathelement *pathlist);
void list(char *dir);
void printenv(char **enviroment, char *arguments);
void setenv(char **enviroment, char *arguments);

#define PROMPTMAX 64
#define MAXARGS   16
#define MAXLINE   128