/**
 * Nome: Margarida Moreira
 * Numero: 93881
 * Ficheiro: HashTable.h
*/


#include "Contactos.h"
#include "Queue.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H

#define SIZE 1023 /*Tamanho de elementos no vetor das hashTables*/

struct node_t{
    node *node_h;
    struct node_t *next_t;
};
typedef struct node_t node_t;

struct hash{
    node_t *front;
};
typedef struct hash hash;

/*Inicializa a hash table*/
void initHash(hash *h);
/*Retrona a chave da posicao na hash table*/
unsigned long djb2(char *str);
/*Verifica se a hash table esta vazia*/
int empty(hash *h);
/*Encontra o nome na hash table*/
node *findName(hash *hashTable[SIZE], unsigned long m, char *nome);
/*Encontra o dominio na hash table*/
int findDomain(hash *hashTable[SIZE], unsigned long m, char *dominio);
/*Adiciona um nome a hash table*/
void add(hash *hashTable[SIZE], unsigned long m, char *nome, node *node_q);
/*Adiciona um dominio a hash table*/
void addDomain(hash *hashTable[SIZE], unsigned long m, char *dominio, node *node_q);
/*Retira nos da hash table*/
void dequeueHash(hash *h);
/*Retira um no especifico da hash table(nome ou dominio)*/
void dequeueHashElement(hash *hashTable[SIZE], unsigned long m, char *nome);
void dequeueHashDomain(hash *hashTable[SIZE], unsigned long m, char *dominio, char *nome);

#endif




