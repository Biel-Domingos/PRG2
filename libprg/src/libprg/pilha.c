#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"


struct pilha {
    int* elementos;
    int topo;
    int capacidade;
};

//criar a pilha na memória
pilha_t* criar_pilha() {
    pilha_t* pilha = (pilha_t*) malloc(sizeof(pilha_t));
    pilha->elementos = (int*) malloc(sizeof(int) * CAPACIDADE_INICIAL);
    pilha->topo = -1;
    pilha->capacidade = CAPACIDADE_INICIAL;
    return pilha;
}

//adiciona elemento na pilha
void empilhar(pilha_t* pilha, int valor) {
    if (pilha->topo + 1 >= pilha->capacidade) {
        printf("Erro: Não é possível empilhar!\n");
        exit(EXIT_FAILURE);
    }
    pilha->topo++;
    pilha->elementos[pilha->topo] = valor;
}

//remover elemento da pilha
int desempilhar(pilha_t* pilha) {
    if (pilha_vazia(pilha)) {
        printf("Erro: A pilha está vazia!\n");
        exit(EXIT_FAILURE);
    }
    int valor = pilha->elementos[pilha->topo];
    pilha->topo--;
    return valor;
}

//mostrar o topo da pilha
int topo(pilha_t* pilha) {
    if (pilha_vazia(pilha)) {
        printf("Erro: Pilha vazia!\n");
        exit(EXIT_FAILURE);
    }
    return pilha->elementos[pilha->topo];
}

bool pilha_vazia(pilha_t* pilha) {
    return pilha->topo == -1;
}

//mostrar tamanho da pilha
int tamanho_pilha(pilha_t* pilha) {
    return pilha->topo + 1;
}

//destruir pilha
void destruir_pilha(pilha_t* pilha) {
    free(pilha->elementos);
    free(pilha);
}