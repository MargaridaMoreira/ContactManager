/**
 * Nome: Margarida Moreira
 * Numero: 93881
 * Ficheiro: Contactos.h
*/

#include <stdlib.h>
#include <string.h>

#ifndef CONTACTOS_H
#define CONTACTOS_H

#define MAX_NOME 1024          /*Numero maximo de caracteres no nome*/
#define MAX_EMAIL 512          /*Numero maximo de caracteres no email*/   
#define MAX_NUMERO 64          /*Numero maximo de caracters no numero*/

typedef struct {
    char *nome;
    char *local;
    char *dominio;
    char *telefone;
} contacto;

/*Verifica se dois contactos sao iguais*/
int equalContacto(contacto a, contacto b);
/*Liberta o espaco alocado para o nome, local, dominio e telefone do contacto*/
void freeContacto(contacto a);

#endif
