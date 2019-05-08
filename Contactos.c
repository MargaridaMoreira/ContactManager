#include "Contactos.h"

int equalContacto(contacto a, contacto b){
    return (!strcmp(a.nome, b.nome) && !strcmp(a.local,b.local) && !strcmp(a.dominio,b.dominio)
    && !strcmp(a.telefone, b.telefone));
}

void freeContacto(contacto a){
    free(a.nome);
    free(a.local);
    free(a.dominio);
    free(a.telefone);
}

