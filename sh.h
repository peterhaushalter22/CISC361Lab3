#include "get_path.h"

int pid;
char *which(char *command, struct pathelement *pathlist);
char **where(char *command, struct pathelement *pathlist);
void list(char *dir);
<<<<<<< HEAD
void printenv(char ** environment, int maxArguments, char **arguments);
=======
void printenv(char **enviroment, char *arguments);
void setenv(char **enviroment, char *arguments);
>>>>>>> ef2a4e51ad1142993b1311c2a02fe726752b2644

#define PROMPTMAX 64
#define MAXARGS   16
#define MAXLINE   128