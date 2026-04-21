#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "libprg/libprg.h"

struct lista {
    int* elementos;
    int tamanho;
    int capacidade;
};

// Criar lista
lista_t* criar_lista() {
    lista_t *lista = (lista_t *) malloc(sizeof(lista_t));
    lista->elementos = (int *) malloc(sizeof(int) * CAPACIDADE_INICIAL);
    lista->tamanho = 0;
    lista->capacidade = CAPACIDADE_INICIAL;
    return lista;
}

// Adicionar elemento na lista
void adicionar(lista_t* lista, int valor) {

    if (lista->tamanho >= lista->capacidade) {
        lista->capacidade *= 2;
        lista->elementos = (int*) realloc(lista->elementos, sizeof(int) * lista->capacidade);
    }
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
}

// Buscar elemento na lista
int buscar(lista_t* lista, int valor) {
    for (int i = 0; i < lista->tamanho; ++i) {
        if (lista->elementos[i] == valor) return i;
    }
    return -1;
}

// Remover da lista
bool remover(lista_t* lista, int valor) {
    int indice = buscar(lista, valor);
    if (indice == -1) return false;

    lista->tamanho--;
    lista->elementos[indice] = lista->elementos[lista->tamanho];
    return true;
}

int primeiro_elemento(lista_t* lista) {
    if (lista->tamanho > 0) return lista->elementos[0];
    return -1; // Ou erro
}

// mostrar tamanho da lista
int tamanho_lista(lista_t* lista) {
    return lista->tamanho;
}

// Destruir lista
void destruir_lista(lista_t* lista) {
    free(lista->elementos);
    free(lista);
}