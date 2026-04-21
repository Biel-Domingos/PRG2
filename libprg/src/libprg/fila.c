//
// Created by adriano.lima on 25/04/25.
//

#include <stdio.h>
#include <stdlib.h>

#include "libprg/libprg.h"

typedef struct fila {
    int *elementos;
    int inicio;
    int fim;
    int capacidade;
    int quantidade;
} fila_t;

fila_t *criar_fila() {
    // Criar estrutura fila e alocar memória
    fila_t *fila = (fila_t *) malloc(sizeof(fila_t));

    // Alocar memória para os elementos da fila
    fila->elementos = (int *) malloc(sizeof(int) * CAPACIDADE_INICIAL);

    // Definir os valores iniciais da fila
    fila->inicio = 0;
    fila->fim = 0;
    fila->capacidade = CAPACIDADE_INICIAL;

    return fila;
}

void enfileirar(fila_t *fila, int valor) {
    if (fila->quantidade == fila->capacidade) {
        printf(("Erro: Fila cheia (overflow)"));
        exit(EXIT_FAILURE);
    }

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->quantidade++;
}

int desenfileirar(fila_t *fila) {

    if (fila->quantidade == 0) {
        printf("Erro: Fila vazia (underflow)");
        exit(EXIT_FAILURE);
    }

    int valor = fila->elementos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->quantidade--;
    return valor;
}

bool fila_vazia(fila_t* fila) {
    return fila->quantidade == 0;
}

bool fila_cheia(fila_t* fila) {
    return fila->quantidade == fila->capacidade;
}

int tamanho_fila(fila_t* fila) {
    return fila->quantidade;
}

int inicio(fila_t* fila) {
    return fila->elementos[fila->inicio];
}

int fim(fila_t* fila) {
    return fila->elementos[fila->fim];
}

 void destruir_fila(fila_t* fila) {
    free(fila->elementos);
    free(fila);
}
