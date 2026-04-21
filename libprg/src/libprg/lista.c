//
// Created by adriano.lima on 06/05/25.
//

#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct lista {
    int* elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
} lista_t;

lista_t* create_list(bool ordenada) {
    // Criar estrutura lista e alocar memória
    lista_t *lista = (lista_t *) malloc(sizeof(lista_t));

    // Alocar memória para os elementos da lista
    lista->elementos = (int *) malloc(sizeof(int) * CAPACIDADE_INICIAL);

    // Definir os valores iniciais da lista
    lista->tamanho = 0;
    lista->capacidade = CAPACIDADE_INICIAL;
    lista->ordenada = ordenada;

    return lista;
}

void add(lista_t* lista, int valor) {

    if (lista->tamanho >= lista->capacidade) {
        lista->capacidade *= 2;
        lista->elementos = (int*) realloc(lista->elementos, sizeof(int) * lista->capacidade);
    }

    if (lista->ordenada) {
        // insere ordenada
        for (int i = lista->tamanho - 1; i >= 0; --i) {

        }
    } else {
        // insere não ordenada
        lista->elementos[lista->tamanho] = valor;
        lista->tamanho++;
    }
}

int search(lista_t* lista, int valor) {

    for (int i = 0; i < lista->tamanho; ++i) {
        if (lista->elementos[i] == valor) {
            return i;
        }
    }

    return -1;
}

bool removel(lista_t* lista, int valor) {

    int indice = search(lista, valor);
    bool resultado = false;

    if (indice > -1) {
        lista->tamanho--;
        lista->elementos[indice] = lista->elementos[lista->tamanho];
        resultado = true;
    }

    return resultado;
}
void destroy_list(lista_t* lista) {
    free(lista->elementos);
    free(lista);
}
// tamanho
// cheia
// capacidade
// vazia