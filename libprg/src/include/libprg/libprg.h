#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdbool.h>

#define CAPACIDADE_INICIAL 20

/*--- PILHA ---*/
typedef struct pilha pilha_t;

pilha_t* criar_pilha();
void empilhar(pilha_t* pilha, int valor);
int desempilhar(pilha_t* pilha);
int topo(pilha_t* pilha);
bool pilha_vazia(pilha_t* pilha);
int tamanho_pilha(pilha_t* pilha);
void destruir_pilha(pilha_t* pilha);

/*--- FILA ---*/
typedef struct fila fila_t;

fila_t* criar_fila();
void enfileirar(fila_t* fila, int valor);
int desenfileirar(fila_t* fila);
bool fila_vazia(fila_t* fila);
bool fila_cheia(fila_t* fila);
int tamanho_fila(fila_t* fila);
int inicio(fila_t* fila);
int fim(fila_t* fila);
void destruir_fila(fila_t* fila);

/*--- LISTA ---*/
typedef struct lista lista_t;

lista_t* criar_lista();
void adicionar(lista_t* lista, int valor);
int buscar(lista_t* lista, int valor);
bool remover(lista_t* lista, int valor);
int tamanho_lista(lista_t* lista);
void destruir_lista(lista_t* lista);

#endif // LIBPRG_LIBPRG_H