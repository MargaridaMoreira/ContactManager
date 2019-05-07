#include <stdlib.h>
#include <string.h>

#ifndef CONTACTOS_H
#define CONTACTOS_H

#define MAX_NOME 1024          /*Numero maximo de caracteres no nome*/
#define MAX_EMAIL 512          /*Numero maximo de caracteres no email*/   
#define MAX_NUMERO 64          /*Numero maximo de caracters no numero*/

typedef struct {
    char *nome;
    char *email;
    char *telefone;
} contacto;

int equalContacto(contacto a, contacto b);
void freeContacto(contacto a);

#endif
