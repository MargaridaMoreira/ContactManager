#include "Queue.h"
#include "Contactos.h"
#include "Funcoes.h"
#include "HashTable.h"

int main(){
    int i;
    char opcao;
    
    queue *contactos;
    hash *hashTable[SIZE];
    hash *hashTableDomain[SIZE];

    contactos = malloc(sizeof(queue));
    initialize(contactos);
    for(i = 0; i < SIZE; i ++){
        hashTable[i] = malloc(sizeof(hash));
        hashTableDomain[i] = malloc(sizeof(hash));
        initHash(hashTable[i]);
        initHash(hashTableDomain[i]);
    }
    
    opcao = getchar();

    while(opcao != 'x'){
        switch(opcao){
            case 'a':
                getchar();
                adiciona(contactos, hashTable, hashTableDomain);
                break;
            case 'l':
                getchar();
                lista_contactos(contactos);
                break;
            case 'p':
                getchar();
                procura_contactos(hashTable);
                break;
            case 'r':
                getchar();
                apaga_contacto(hashTable,hashTableDomain, contactos);
                break;
            case 'e':
                getchar();
                altera_email(hashTable, hashTableDomain);
                break;
            case 'c':
                getchar();
                conta_dominios(hashTableDomain);
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
        dequeueHash(hashTableDomain[i]);
        free(hashTable[i]);
        free(hashTableDomain[i]);
    }


    return 0;
}
