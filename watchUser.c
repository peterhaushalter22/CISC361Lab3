#include "sh.h"
#include <utmpx.h>
#include <unistd.h>

extern linkedList *listOfUsersHead;

void *watchUser(){
    sleep(20);

    struct utmpx *up;
    linkedList *temp = listOfUsersHead;
    char *name;

    while(temp != NULL){
        name = temp->name;
        setutxent();
        up = getutxent();
        while (up != NULL){
            if (strcmp(up->ut_user, name) == 0 && temp->isOn == ON){
                printf("%s has logged on %s from %s\n", up->ut_user, up->ut_line, up->ut_host);
            }
            up = getutxent();
        }

        temp = temp->next;
    }

    // setutxent();
    // up = getutxent();
    // while (up != NULL){
    //     if (strcmp(up->ut_user, name) == 0){
    //         printf("%s has logged on %s from %s\n", up->ut_user, up->ut_line, up->ut_host);
    //     }
    //     up = getutxent();
    // }

    return 0;
}
