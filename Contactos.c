#include "Contactos.h"
#include <string.h>

int equalContacto(contacto a, contacto b){
    return (!strcmp(a.nome, b.nome) && !strcmp(a.email,b.email) && !strcmp(a.telefone, b.telefone));
}

void freeContacto(contacto a){
    free(a.nome);
    free(a.email);
    free(a.telefone);
}

