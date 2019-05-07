#include "Queue.h"

void initialize(queue *q){
    q -> count = 0;
    q -> front = NULL;
    q -> rear = NULL;
}

int isEmpty(queue *q){
    return (q -> rear == NULL);
}

node* enqueue(queue *q, contacto value){
    node *temp;
    temp = malloc(sizeof(node));
    temp -> data = value;
    temp -> next = NULL;

    if(!isEmpty(q)){
        temp -> prev = q -> rear;   
        q -> rear -> next = temp;
        q -> rear = temp;

    } else {
        q -> front = q -> rear = temp;
        temp -> prev = NULL;
    }
    q -> count++;
    return (temp);
}

void dequeue(queue *q){
    node *temp;

    temp = q -> front;
    q -> front = q -> front -> next;
    q -> count --;
    freeContacto(temp -> data);
    free(temp);
}

void dequeueElement(queue *q, node *value){ 
    node *temp;
    temp = q -> front;

    if(temp == value){
        q -> front = value -> next;
    }

    if (value -> next != NULL){
        value -> next  -> prev = value -> prev;
    } else {
        q -> rear = value -> prev;
    }

    if(value -> prev != NULL){
        value -> prev -> next = value -> next;
    }


    freeContacto(value -> data);
    free(value);
    q -> count --;

}

void display(node *head){
    node *temp;
    temp = head;
    while(temp != NULL){
        printf("%s %s %s\n", temp -> data.nome, temp -> data.email, temp -> data.telefone); 
        temp = temp -> next;
    }
}


