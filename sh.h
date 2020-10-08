#include "get_path.h"

int pid;
char *which(char *command, struct pathelement *pathlist);
char **where(char *command, struct pathelement *pathlist);
void list(char **arguments);
void printenv(char ** environment, int maxArguments, char **arguments);
void cd(char *cd);
void pwd();
void killProc(char **arguments);
#define PROMPTMAX 64
#define MAXARGS   16
#define MAXLINE   128