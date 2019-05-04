#include "Queue.h"
#include "Contactos.h"
#include "Funcoes.h"
#include "HashTable.h"

int main(){
    queue *contactos;
    contactos = malloc(sizeof(queue));
    initialize(contactos);

    //hash *table;
    //table = malloc(sizeof(hash));
    //initHash(table);

    char opcao;
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
    //free(table);
    return 0;
}
