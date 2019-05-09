#include "Funcoes.h"

#define MAX_INPUT 1600

void adiciona(queue *q, hash *hashTable[SIZE], hash *hashTableDomain[SIZE]){
    char input[MAX_INPUT], *token, *info[3], *email[2];
       
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

    i = 0; 
    token = strtok(info[1], "@");
    while(token != NULL){
        email[i] = token;
        token = strtok(NULL, "@");
        i ++;
    }

    
        
    a.nome = malloc((strlen(info[0])+1) * sizeof(char));
    a.local = malloc((strlen(email[0])+1)*sizeof(char));
    a.dominio = malloc((strlen(email[1])+1) * sizeof(char));
    a.telefone = malloc((strlen(info[2])+1) * sizeof(char));

    strcpy(a.nome, info[0]);
    strcpy(a.local, email[0]);
    strcpy(a.dominio, email[1]);
    strcpy(a.telefone, info[2]);

    n = findName(hashTable, SIZE, input);

    if(n == NULL){
        contacto = enqueue(q,a);
        add(hashTable, SIZE, a.nome, contacto);
        addDomain(hashTableDomain, SIZE, a.dominio, contacto);
    } else {
        free(a.nome);
        free(a.local);
        free(a.dominio);
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
        printf("%s %s@%s %s\n", n -> data.nome, n -> data.local, n -> data.dominio, n -> data.telefone);
    }
}

void altera_email(hash *hashTable[SIZE], hash *hashTableDomain[SIZE]){
    char input[MAX_INPUT], *token, *info[2], *email[2];   
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

    i = 0; 
    token = strtok(info[1], "@");
    while(token != NULL){
        email[i] = token;
        token = strtok(NULL, "@");
        i ++;
    }

    n = findName(hashTable, SIZE, info[0]);

    if(n == NULL){
        printf("Nome inexistente.\n");
    } else {
        dequeueHashDomain(hashTableDomain, SIZE, n -> data.dominio, n -> data.nome);
        n -> data.local = realloc(n -> data.local, (strlen(email[0])+1)*sizeof(char));
        n -> data.dominio = realloc(n -> data.dominio, (strlen(email[1])+1)*sizeof(char));
        strcpy(n -> data.local, email[0]); 
        strcpy(n -> data.dominio, email[1]); 
        addDomain(hashTableDomain, SIZE, n -> data.dominio, n);
    }
}

void apaga_contacto(hash *hashTable[SIZE],hash *hashTableDomain[SIZE], queue *q){
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
        dequeueHashElement(hashTable, SIZE, input);
        dequeueHashDomain(hashTableDomain, SIZE, n->data.dominio, input);
        dequeueElement(q, n);

    }
}

void conta_dominios(hash *hashTableDomain[SIZE]){
    char input[MAX_INPUT];   
    int c, i = 0, num;

    c = getchar();
    for(i = 0; i < MAX_INPUT-1 && c != '\n'; i++){
        input[i] = c;
        c = getchar();
    }
    input[i] = '\0';

    num = findDomain(hashTableDomain, SIZE, input);
    printf("%s:%d\n", input, num);

}