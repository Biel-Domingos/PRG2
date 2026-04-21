#include <stdio.h>
#include <stdlib.h>

#include "libprg/libprg.h"

typedef struct pilha {
    int* elementos;
    int topo;
    int capacidade;
} pilha_t;

pilha_t* create_stack() {

    // Criar a estrutura pilha e alocar memória
    pilha_t* pilha = (pilha_t*) malloc(sizeof(pilha_t));

    // Alocar memória para os elementos da pilha
    pilha->elementos = (int*) malloc(sizeof(int) * CAPACIDADE_INICIAL);

    // Definir os valores iniciais da pilha
    pilha->topo = -1;
    pilha->capacidade = CAPACIDADE_INICIAL;

    return pilha;
}

void push(pilha_t* pilha, int valor) {

    if (pilha->topo + 1 >= pilha->capacidade) {
        printf("Erro: Não é possível empilhar!");
        exit(EXIT_FAILURE);
    }

    pilha->topo++;
    pilha->elementos[pilha->topo] = valor;
}

int pop(pilha_t* pilha) {

    if (pilha->topo < 0) {
        printf("Erro: A pilha está vazia!");
        exit(EXIT_FAILURE);
    }

    int valor = pilha->elementos[pilha->topo];
    pilha->topo--;

    return valor;
}

bool emptys(pilha_t* pilha) {

    return pilha->topo == -1;
}

int sizes(pilha_t* pilha) {

    return pilha->topo + 1;
}

void detroy_stack(pilha_t* pilha) {

    free(pilha->elementos);
    free(pilha);
}