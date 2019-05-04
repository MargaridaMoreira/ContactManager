#include "Contactos.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef HASHTABLE_H
#define HASHTABLE_H

struct node_t{
    contacto *c;
    struct node_t *next_t;
};
typedef struct node_t node_t;

struct hash{
    node_t *front;
};
typedef struct hash hash;

void initHash(hash *h);
int key(char nome[]);
//void addContacto;
//void removeContacto;
//contacto findContacto(int key);
//void deleteHash;

#endif




