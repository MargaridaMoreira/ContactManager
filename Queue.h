#ifndef QUEUE_H
#define QUEUE_H

#include "Structs.h"

struct queue{
    int count;
    node *front;
    node *rear;
};
typedef struct queue queue;

struct node{
    contacto data;
    struct node *link;
};
typedef struct node node;

void initialize (queue *q);
int isEmpty(queue *q);
void enqueue(queue *q, contacto value);
void dequeue(queue *q);



#endif