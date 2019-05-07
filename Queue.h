#include "Contactos.h"
#include <stdio.h>

#ifndef QUEUE_H
#define QUEUE_H

struct node{
    contacto data;
    struct node *next;
    struct node *prev;
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
node *enqueue(queue *q, contacto value);
void dequeue(queue *q);
void dequeueElement(queue *q, node *value);
void display(node *head);

#endif