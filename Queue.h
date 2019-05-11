/**
 * Nome: Margarida Moreira
 * Numero: 93881
 * Ficheiro: Queue.h
*/

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

/*Inicializa a fila*/
void initialize (queue *q);
/*Verifica se a fila esta vazia*/
int isEmpty(queue *q);
/*Adiciona um no a fila*/
node *enqueue(queue *q, contacto value);
/*Retira o primeiro no da fila*/
void dequeue(queue *q);
/*Retira um elemento especifico da fila*/
void dequeueElement(queue *q, node *value);
/*Lista os elementos da fila*/
void display(node *head);

#endif