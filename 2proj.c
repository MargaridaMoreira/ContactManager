#include <stdio.h>
#include "Queue.h"

#define MAX_INPUT 1610

void adiciona(queue q);


int main(){
    char opcao;
    queue *contactos;
    contactos = malloc(sizeof(queue));
    initialize(contactos);

    opcao = getchar();

    while(opcao != 'x'){
        switch(opcao){
            case 'a':
                adiciona(queue contactos);
                getchar();
                break;
            default:
                break;
        }
        opcao = getchar();
    }
    return 0;
}

void adiciona(queue q){
    char input[MAX_INPUT];
    int c, i = 0;

    c = getchar();
    for(i = 0; i < MAX_INPUT && c != '\n'; i++){
        input[i] = c;
        c = getchar();
    }
    input[i] = '\0';



}