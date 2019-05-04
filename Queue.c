#include "Queue.h"

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
    temp -> next = NULL;

    if(!isEmpty(q)){
        q -> rear -> next = temp;
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
    q -> front = q -> front -> next;
    q -> count --;
    free(temp -> data.nome);
    free(temp -> data.email);
    free(temp -> data.telefone);
    free(temp);
}

void display(node *head){
    node *temp;
    temp = head;
    while(temp != NULL){
        printf("%s %s %s\n", temp -> data.nome, temp -> data.email, temp -> data.telefone); 
        temp = temp -> next;
    }
}


