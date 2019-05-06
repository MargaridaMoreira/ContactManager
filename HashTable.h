#include "Contactos.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef HASHTABLE_H
#define HASHTABLE_H

#define SIZE 10

struct node_t{
    node *n;
    struct node_t *next_t;
};
typedef struct node_t node_t;

struct hash{
    node_t *front;
};
typedef struct hash hash;

hash hashArray[SIZE];

void initHash(hash *h);
int key(char nome[]);
//void addContacto(hash hashArray[SIZE], contacto value);
void removeContacto(hash hashArray[SIZE], char nome[]);

#endif




