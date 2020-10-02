#include "get_path.h"

struct pathelement *get_path(){
  /* path is a copy of the PATH and p is a temp pointer */
  char *path, *p, *token;

  /* tmp is a temp point used to create a linked list and pathlist is a
     pointer to the head of the list */
  struct pathelement *current, *pathlist = NULL;

  p = getenv("PATH");	

  path = malloc((strlen(p)+1)*sizeof(char));
  strncpy(path, p, strlen(p));
  path[strlen(p)] = '\0';

  token = strtok(path, ":");

  do{
    if ( !pathlist ){
      current = calloc(1, sizeof(struct pathelement));
      pathlist = current;
    }else{
      current->next = calloc(1, sizeof(struct pathelement));
      current = current->next;
    }

    current->element = p;	
    current->next = NULL;

    token = strtok(NULL, ":");

  } while ( token != NULL );

  free(path);

  return pathlist;
} /* end get_path() */