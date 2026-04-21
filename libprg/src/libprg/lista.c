#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"

typedef struct lista {
    int* elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
} lista_t;

lista_t* criar_lista() {
    lista_t *lista = (lista_t *) malloc(sizeof(lista_t));
    lista->elementos = (int *) malloc(sizeof(int) * CAPACIDADE_INICIAL);

    lista->tamanho = 0;
    lista->capacidade = CAPACIDADE_INICIAL;

    // MUDANÇA AQUI: Defina como false ou true manualmente,
    // já que o criar_lista() não recebe mais esse parâmetro.
    lista->ordenada = false;

    return lista;
}

void adicionar(lista_t* lista, int valor) {
    if (lista->tamanho >= lista->capacidade) {
        lista->capacidade *= 2;
        lista->elementos = (int*) realloc(lista->elementos, sizeof(int) * lista->capacidade);
    }

    if (lista->ordenada) {
        // lógica de inserção ordenada (pode deixar vazio por enquanto)
    } else {
        lista->elementos[lista->tamanho] = valor;
        lista->tamanho++;
    }
}

int buscar(lista_t* lista, int valor) {
    for (int i = 0; i < lista->tamanho; ++i) {
        if (lista->elementos[i] == valor) {
            return i;
        }
    }
    return -1;
}

bool remover(lista_t* lista, int valor) {
    // MUDANÇA AQUI: Era 'search', mudei para 'buscar'
    int indice = buscar(lista, valor);
    bool resultado = false;

    if (indice > -1) {
        lista->tamanho--;
        lista->elementos[indice] = lista->elementos[lista->tamanho];
        resultado = true;
    }

    return resultado;
}

void destruir_lista(lista_t* lista) {
    free(lista->elementos);
    free(lista);
}