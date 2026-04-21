#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"


struct fila {
    int *elementos;
    int inicio;
    int fim;
    int capacidade;
    int quantidade;
};

//criar a fila
fila_t *criar_fila() {
    fila_t *fila = (fila_t *) malloc(sizeof(fila_t));
    fila->elementos = (int *) malloc(sizeof(int) * CAPACIDADE_INICIAL);

    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade = 0;
    fila->capacidade = CAPACIDADE_INICIAL;

    return fila;
}

//adiciona elemento na fila
void enfileirar(fila_t *fila, int valor) {
    if (fila_cheia(fila)) {
        printf("Erro: Fila cheia!\n");
        exit(EXIT_FAILURE);
    }

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->quantidade++;
}

//remover elemento da fila
int desenfileirar(fila_t *fila) {
    if (fila_vazia(fila)) {
        printf("Erro: Fila vazia!\n");
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

// mostrar tamanho da fila
int tamanho_fila(fila_t* fila) {
    return fila->quantidade;
}

//mostrar o topo da fila
int inicio(fila_t* fila) {
    if (fila_vazia(fila)) exit(EXIT_FAILURE);
    return fila->elementos[fila->inicio];
}

int fim(fila_t* fila) {
    if (fila_vazia(fila)) exit(EXIT_FAILURE);
    int pos_ultimo = (fila->fim - 1 + fila->capacidade) % fila->capacidade;
    return fila->elementos[pos_ultimo];
}

//destruir fila
void destruir_fila(fila_t* fila) {
    free(fila->elementos);
    free(fila);
}