/**
 * Nome: Margarida Moreira
 * Numero: 93881
 * Ficheiro: Funcoes.h
*/

#include "Contactos.h"
#include "Queue.h"
#include "HashTable.h"

#ifndef FUNCOES_H
#define FUNCOES_H

#define MAX_INPUT 1600 /*Numero maximo de caracters que sao lidos do stdin*/

/*Adiciona um contacto a fila*/
void adiciona(queue *q, hash *hashTable[SIZE], hash *hashTableDomain[SIZE]);
/*Lista a fila de contactos*/
void lista_contactos(queue *q);
/*Procura e retorna o contacto se este existir*/
void procura_contactos(hash *hashTable[SIZE]);
/*Altera o email de um contacto*/
void altera_email(hash *hashTable[SIZE], hash *hashTableDomain[SIZE]);
/*Apaga um contacto da fila*/
void apaga_contacto(hash *hashTable[SIZE],hash *hashTableDomain[SIZE], queue *q);
/*Conta as ocorrencias de um dominio na fila de contactos*/
void conta_dominios(hash *hashTableDomain[SIZE]);

#endif