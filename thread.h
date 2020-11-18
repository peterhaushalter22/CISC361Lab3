#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#include <unistd.h>  //included files and libraries
//Definitions
void t_init(void);
void t_shutdown(void);
int t_create(void (*func)(int), int thr_id, int pri);

struct tcb  //structure
{
    int thread_id;
    int thread_priority;
    ucontext_t *thread_context;
    struct tcb *next;
};

typedef struct tcb tcb;

tcb *running;
tcb *ready;
