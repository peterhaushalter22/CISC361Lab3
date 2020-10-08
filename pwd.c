#include "sh.h"

void pwd(){
    char *workingDirectory;

	printf("Executing built-in [pwd]\n");
	workingDirectory = getcwd(NULL, 0);
    printf("%s\n", workingDirectory);
    free(workingDirectory);
}