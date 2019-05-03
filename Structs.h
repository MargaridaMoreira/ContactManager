#ifndef QUEUE_H
#define QUEUE_H

#define MAX_NOME 1024          /*Numero maximo de caracteres no nome*/
#define MAX_EMAIL 512          /*Numero maximo de caracteres no email*/   
#define MAX_NUMERO 64          /*Numero maximo de caracters no numero*/

typedef struct {
    char nome[MAX_NOME];
    char email[MAX_EMAIL];
    char numero[MAX_NUMERO];
} contacto;

struct node{
    contacto data;
    struct node *link;
};
typedef struct node node;

#endif
