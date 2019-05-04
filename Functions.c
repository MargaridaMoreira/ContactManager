#include "Functions.h"

#define MAX_INPUT 1610

void adiciona(queue *q){
    char input[MAX_INPUT], *token, *info[3] ;   
    int c, i = 0;
    contacto a;

    c = getchar();
    for(i = 0; i < MAX_INPUT-1 && c != '\n'; i++){
        input[i] = c;
        c = getchar();
    }
    input[i] = '\0';

    i = 0;
    token = strtok(input, " ");
    while(token != NULL){
        info[i] = token;
        token = strtok(NULL, " "); 
        i ++;
    }
    
    strcpy(a.nome, info[0]);
    strcpy(a.email, info[1]);
    strcpy(a.telefone, info[2]);

    enqueue(q, a);

}

