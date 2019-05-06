#include "HashTable.h"

void initHash(hash *h){
    h -> front = NULL;
}

int key(char nome[]){
    int i = nome[0];
    if (i < 10){
        return i;
    } else if (i == 95){
        return 10;
    } else if (i >= 65 && i <=90){
        return (i-54);
    } else {
        return (i-69);
    }
}

void removeContacto(hash hashArray[SIZE], char nome[]){
    int element = key(nome);
    hash h = hashArray[element];
}