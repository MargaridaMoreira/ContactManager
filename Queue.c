#include "Queue.h"
#include "Contactos.h"

#include <stdio.h>
#include <stdlib.h>

void initialize(queue *q){
    q -> count = 0;
    q -> front = NULL;
    q -> rear = NULL;
}

int isEmpty(queue *q){
    return (q -> rear == NULL);
}

void enqueue(queue *q, contacto value){
    node *temp;
    temp = malloc(sizeof(node));
    temp -> data = value;
    temp -> link = NULL;

    if(!isEmpty(q)){
        q -> rear -> link = temp;
        q -> rear = temp;
    } else {
        q -> front = q -> rear = temp;
    }
    q -> count++;
}

void dequeue(queue *q){
    int n = q -> front -> data;
    node *temp;

    temp = q -> front;
    q -> front = q -> front -> link;
    q -> count --;
    free(temp);
}


