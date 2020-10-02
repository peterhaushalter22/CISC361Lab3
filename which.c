#include "get_path.h"

char *which(char *command, struct pathelement *path){
  char cmd[64], *pathFound;
  int  found;

  found = 0;
  while (path) {

    sprintf(cmd, "%s/%s", path->element, command);

    //checks if the command is executable.
    if (access(cmd, X_OK) == 0) {
      found = 1;
      break;
    }

    path = path->next;
  }

  if (found) {
    pathFound = malloc(strlen(cmd)+1);
    strcpy(pathFound, cmd);
    return pathFound;
  }else{
    return (char *) NULL;
  }

}