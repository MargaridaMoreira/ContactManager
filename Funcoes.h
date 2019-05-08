#include "Contactos.h"
#include "Queue.h"
#include "HashTable.h"

#ifndef FUNCOES_H
#define FUNCOES_H

#define MAX_INPUT 1600

void adiciona(queue *q, hash *hashTable[SIZE], hash *hashTableDomain[SIZE]);
void lista_contactos(queue *q);
void procura_contactos(hash *hashTable[SIZE]);
void altera_email(hash *hashTable[SIZE]);
void apaga_contacto(hash *hashTable[SIZE],hash *hashTableDomain[SIZE], queue *q);
void conta_dominios(hash *hashTableDomain[SIZE]);

#endif