/**
 * Nome: Margarida Moreira
 * Numero: 93881
 * Ficheiro: HashTable.c
*/

#include "HashTable.h"

void initHash(hash *h){
    h -> front = NULL;
}

unsigned long djb2(char *str){
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)){
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

int empty(hash *h){
    return (h -> front == NULL);
}


node *findName(hash *hashTable[SIZE], unsigned long m, char *nome){
    unsigned long key = djb2(nome) % m;
    
    hash *h = hashTable[key];
    node_t *temp;

    if(h -> front == NULL){
        return NULL;
    }
    
    temp = h -> front;
    while(temp != NULL && strcmp(temp -> node_h -> data.nome, nome)){
        temp = temp -> next_t;
    }

    if(temp == NULL){
        return NULL;
    } else {    
        return temp -> node_h;
    }
}

int findDomain(hash *hashTable[SIZE], unsigned long m, char *dominio){
    unsigned long key = djb2(dominio) % m;
    int count = 0;
    
    hash *h = hashTable[key];
    node_t *temp;

    if(h -> front == NULL){
        return count;
    }

    temp = h -> front;
    while(temp != NULL){
        if(!strcmp(temp -> node_h -> data.dominio, dominio)){
            count ++;
        }
        temp = temp -> next_t;
    }
    return count;

}

void add(hash *hashTable[SIZE], unsigned long m, char *nome, node *node_q){
    node_t *temp = malloc (sizeof(node_t));
    unsigned long key = djb2(nome) % m;
   
    hash *h = hashTable[key];

    temp -> node_h = node_q;
    temp -> next_t = NULL;

    if(!empty(h)){ 
        temp -> next_t = h -> front;
        h -> front = temp;

    } else {
        h -> front =  temp;
    }
}

void addDomain(hash *hashTable[SIZE], unsigned long m, char *dominio, node *node_q){
    node_t *temp = malloc (sizeof(node_t));
    unsigned long key = djb2(dominio) % m;
   
    hash *h = hashTable[key];

    temp -> node_h = node_q;
    temp -> next_t = NULL;

    if(!empty(h)){ 
        temp -> next_t = h -> front;
        h -> front = temp;

    } else {
        h -> front =  temp;
    }
}

void dequeueHash(hash *h){
    node_t *temp;

    while(!empty(h)){
        temp = h -> front;
        h -> front = h -> front -> next_t;
        free(temp);
    }
    
}

void dequeueHashElement(hash *hashTable[SIZE], unsigned long m, char *nome){
    unsigned long key = djb2(nome) % m;
    hash *h = hashTable[key];
    node_t *head = h -> front;
    node_t *prev, *temp = head;


    if (temp != NULL && !strcmp(temp -> node_h -> data.nome, nome)){
        h -> front = temp -> next_t;
        free(temp);
        return;
    }

    while(temp != NULL && strcmp(temp -> node_h -> data.nome, nome)){
        prev = temp;
        temp = temp -> next_t;
    }

    if (temp == NULL){
        return;
    }

    prev -> next_t = temp -> next_t;
    free(temp);
}

void dequeueHashDomain(hash *hashTable[SIZE], unsigned long m, char *dominio, char *nome){
    unsigned long key = djb2(dominio) % m;
    hash *h = hashTable[key];
    node_t *head = h -> front;
    node_t *prev, *temp = head;


    if (temp != NULL && !strcmp(temp -> node_h -> data.dominio, dominio) && !strcmp(temp -> node_h -> data.nome, nome)){
        h -> front = temp -> next_t;
        free(temp);
        return;
    }

    while(temp != NULL ){
        if(!strcmp(temp -> node_h -> data.dominio, dominio) && !strcmp(temp -> node_h -> data.nome, nome)){
            break;
        }
        prev = temp;
        temp = temp -> next_t;
    }

    if (temp == NULL){
        return;
    }

    prev -> next_t = temp -> next_t;
    free(temp);
}



