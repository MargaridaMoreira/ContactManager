#include "Queue.h"

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
    contacto n = q -> front -> data;
    node *temp;

    temp = q -> front;
    q -> front = q -> front -> link;
    q -> count --;
    free(temp);
}

void display(node *head){
    node *temp;
    temp = head;

    if(head == NULL){
        printf("The Queue is empty\n");
    } else {
        while(temp != NULL){
            printf("%s\n%s\n%s\n", temp -> data.nome, temp ->data.email, temp -> data.telefone);
            temp = temp -> link;
        }
        printf("\n");
    }
}


