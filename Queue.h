#ifndef QUEUE_H
#define QUEUE_H

#include "Structs.h"

struct queue{
    int count;
    node *front;
    node *rear;
};
typedef struct queue queue;

void initialize (queue *q);
int isEmpty(queue *q);
void enqueue(queue *q, int value);
int dequeue(queue *q);
void display(node *head);

#endif