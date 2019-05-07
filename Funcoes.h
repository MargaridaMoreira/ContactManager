#include "Contactos.h"
#include "Queue.h"
#include "HashTable.h"

#ifndef FUNCOES_H
#define FUNCOES_H

#define MAX_INPUT 1600

void adiciona(queue *q, hash *hashTable[SIZE]);
void lista_contactos(queue *q);
void procura_contactos(hash *hashTable[SIZE]);
void altera_email(hash *hashTable[SIZE]);
void apaga_contacto(hash *hashTable[SIZE], queue *q);

#endif