#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Contactos.h"
#include "Functions.h"

int main(){
    char opcao;
    queue *contactos;
    contactos = malloc(sizeof(queue));
    initialize(contactos);
    opcao = getchar();

   /* if (opcao == 'a'){
        getchar();
        adiciona(contactos);
    }*/
    while(opcao != 'x'){
        switch(opcao){
            case 'a':
                getchar();
                adiciona(contactos);
                break;
            default:
                break;
        }
        opcao = getchar();
    }
    display(contactos -> front);
    dequeue(contactos);
    free(contactos);
    return 0;
}
