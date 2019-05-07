#include "Funcoes.h"

#define MAX_INPUT 1610

void adiciona(queue *q, hash *hashTable[SIZE]){
    char input[MAX_INPUT], *token, *info[3] ;   
    int c, i = 0;
    contacto a;
    node *n;

    c = getchar();
    for(i = 0; i < MAX_INPUT-1 && c != '\n'; i++){
        input[i] = c;
        c = getchar();
    }
    input[i] = '\0';

    i = 0;
    token = strtok(input, " ");
    while(token != NULL){
        info[i] = token;
        token = strtok(NULL, " "); 
        i ++;
    }
        
    a.nome = malloc((strlen(info[0])+1) * sizeof(char));
    a.email = malloc((strlen(info[1])+1) * sizeof(char));
    a.telefone = malloc((strlen(info[2])+1) * sizeof(char));

    strcpy(a.nome, info[0]);
    strcpy(a.email, info[1]);
    strcpy(a.telefone, info[2]);

    if(!searchName(hashTable, SIZE, a.nome)){
        n = enqueue(q,a);
        add(hashTable, SIZE, a.nome, n);
    } else {
        free(a.nome);
        free(a.email);
        free(a.telefone);
        printf("Nome existente.\n");
    }

}

void lista_contactos(queue *q){
    display(q -> front);
}

