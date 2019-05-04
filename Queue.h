#include "Contactos.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H

struct node{
    contacto data;
    struct node *next;
};
typedef struct node node;

struct queue{
    int count;
    node *front;
    node *rear;
};
typedef struct queue queue;

void initialize (queue *q);
int isEmpty(queue *q);
void enqueue(queue *q, contacto value);
void dequeue(queue *q);
void display(node *head);

#endif