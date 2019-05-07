#include "Queue.h"
#include "Contactos.h"
#include "Funcoes.h"
#include "HashTable.h"

int main(){
    int i;
    char opcao;
    
    queue *contactos;
    hash *hashTable[SIZE];

    contactos = malloc(sizeof(queue));
    initialize(contactos);
    for(i = 0; i < SIZE; i ++){
        hashTable[i] = malloc(sizeof(hash));
        initHash(hashTable[i]);
    }
    
    opcao = getchar();

    while(opcao != 'x'){
        switch(opcao){
            case 'a':
                getchar();
                adiciona(contactos, hashTable);
                break;
            case 'l':
                getchar();
                lista_contactos(contactos);
                break;
            case 'p':
                getchar();
                procura_contactos(hashTable);
                break;
            /*case 'r':
                getchar();
                apaga_contacto(hashTable);*/
            case 'e':
                getchar();
                altera_email(hashTable);
                break;
            default:
                break;
        }
        opcao = getchar();
    }
    
    while(contactos -> count != 0){
        dequeue(contactos);
    }
    free(contactos);
    for(i = 0; i < SIZE; i ++){
        dequeueHash(hashTable[i]);
        free(hashTable[i]);
    }


    return 0;
}
