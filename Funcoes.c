#include "Funcoes.h"

#define MAX_INPUT 1600

void adiciona(queue *q, hash *hashTable[SIZE]){
    char input[MAX_INPUT], *token, *info[3];   
    int c, i = 0;
    contacto a;
    node *n, *contacto;

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

    n = findName(hashTable, SIZE, input);

    if(n == NULL){
        contacto = enqueue(q,a);
        add(hashTable, SIZE, a.nome, contacto);
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

void procura_contactos(hash *hashTable[SIZE]){
    char input[MAX_NOME];
    int c, i;
    node *n;

    c = getchar();
    for(i = 0; i < MAX_INPUT-1 && c != '\n'; i++){
        input[i] = c;
        c = getchar();
    }
    input[i] = '\0';

    n = findName(hashTable, SIZE, input);

    if(n == NULL){
        printf("Nome inexistente.\n");
    } else {
        printf("%s %s %s\n", n -> data.nome, n -> data.email, n -> data.telefone);
    }
}

void altera_email(hash *hashTable[SIZE]){
    char input[MAX_INPUT], *token, *info[2];   
    int c, i = 0;
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

    n = findName(hashTable, SIZE, info[0]);

    if(n == NULL){
        printf("Nome inexistente.\n");
    } else {
        n -> data.email = realloc(n -> data.email, (strlen(info[1])+1)*sizeof(char));
        strcpy(n -> data.email, info[1]); 
    }
}

/*void apaga_contacto(hash *hashTable[SIZE]){

}*/