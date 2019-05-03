#include <stdio.h>

#include "Queue.h"


#define MAX_NOME 1024          /*Numero maximo de caracteres no nome*/
#define MAX_EMAIL 512          /*Numero maximo de caracteres no email*/   
#define MAX_NUMERO 64          /*Numero maximo de caracters no numero*/

typedef struct {
    char nome[MAX_NOME];
    char email[MAX_EMAIL];
    char numero[MAX_NUMERO];
} contacto;

int main(){
    char opcao;

    opcao = getchar();

    while(opcao != 'x'){
        switch(opcao){
            case 'a':
                getchar();
                break;
            default:
                break;
        }
        opcao = getchar();
    }
    return 0;
}