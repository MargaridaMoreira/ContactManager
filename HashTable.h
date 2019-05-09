#include "Contactos.h"
#include "Queue.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H

#define SIZE 1023

struct node_t{
    node *node_h;
    struct node_t *next_t;
};
typedef struct node_t node_t;

struct hash{
    node_t *front;
};
typedef struct hash hash;

void initHash(hash *h);
unsigned long djb2(char *str);
int empty(hash *h);
node *findName(hash *hashTable[SIZE], unsigned long m, char *nome);
int findDomain(hash *hashTable[SIZE], unsigned long m, char *dominio);
void add(hash *hashTable[SIZE], unsigned long m, char *nome, node *node_q);
void addDomain(hash *hashTable[SIZE], unsigned long m, char *dominio, node *node_q);
void dequeueHash(hash *h);
void dequeueHashElement(hash *hashTable[SIZE], unsigned long m, char *nome);
void dequeueHashDomain(hash *hashTable[SIZE], unsigned long m, char *dominio, char *nome);

#endif




