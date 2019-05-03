#include "Contactos.h"
#include "Queue.c"

#include <stdio.h>

void adiciona(queue q){
    char input[MAX_INPUT], *token, *info[3];   
    int c, i = 0;
    contacto c;

    c = getchar();
    for(i = 0; i < MAX_INPUT && c != '\n'; i++){
        input[i] = c;
        c = getchar();
    }
    input[i] = '\0';

    i = 0;
    token = strtok(input, " \n");
    while(token != NULL){
        token = info[3];
        i ++;
    }
    


}

