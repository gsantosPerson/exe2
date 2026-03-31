#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha{
    int *valores;
    int topo;
    int tam;
}Pilha;

Pilha *criar(int tam){
    Pilha *p = malloc(sizeof(Pilha));
    p->valores = malloc(tam * sizeof(int));
    p->topo = -1;
    p->tam = tam;
}

int isFull(Pilha *p){
    return p->topo == p->tam - 1;
}

int isEmpty(Pilha *p){
    return p->topo == -1;
}


int push(Pilha *p, int valor){
    if(isFull(p)){
        printf("\nPilha cheia\n");
        return 0;
    }

    p->valores[++p->topo] = valor;
    return 1;
}

int pop(Pilha *p){
    if(isEmpty(p)){
        printf("\nPilha vazia\n");
        return 0;
    }

    int valor = p->valores[p->topo--];
    return valor;
}

void sequencia(){

    int tam;
    printf("Tamanho: ");
    scanf("%d", &tam);

    Pilha *p = criar(tam);
    int valor[tam];
    for(int i = 0; i < tam; i++){
        printf("Valor %d: ", i+1);
        scanf("%d", &valor[i]);
    }

    for(int i = 0; i < tam; i++){
        push(p, valor[i]);
    }

    while(!isEmpty(p)){
        printf("%d ", pop(p));
    }

    free(p->valores);
    free(p);
}

int main(){

sequencia();

return 0;
}
