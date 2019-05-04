#include "Queue.h"
#include "Contactos.h"
#include "Funcoes.h"

int main(){
    char opcao;
    queue *contactos;
    contactos = malloc(sizeof(queue));
    initialize(contactos);
    opcao = getchar();

    while(opcao != 'x'){
        switch(opcao){
            case 'a':
                getchar();
                adiciona(contactos);
                break;
            case 'l':
                getchar();
                lista_eventos(contactos);
            default:
                break;
        }
        opcao = getchar();
    }
    while(contactos -> count != 0){
        dequeue(contactos);
    }
    free(contactos);
    return 0;
}
