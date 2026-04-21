#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"

//
// int main() {
//     // 2. Instancie uma pilha
//     pilha_t* p = criar_pilha();
//
//     // 3. Insira dez números inteiros na pilha
//     printf("Empilhando: ");
//     for (int i = 1; i <= 10; i++) {
//         int valor = i * 10;
//         printf("%d ", valor);
//         empilhar(p, valor);
//     }
//
//     // 4. Imprima o topo da pilha e o tamanho da pilha
//     printf("\n\nTopo atual: %d", topo(p));
//     printf("\nTamanho da pilha: %d", tamanho_pilha(p));
//
//     // 5. Remova três números da pilha
//     printf("\n\nDesempilhando 3 elementos...");
//     for (int i = 0; i < 3; i++) {
//         desempilhar(p);
//     }
//
//     // 6. Imprima todos os números da pilha (esvaziando-a)
//     printf("\nElementos restantes na pilha: ");
//     while (!pilha_vazia(p)) {
//         printf("%d ", desempilhar(p));
//     }
//
//     // 7. Destrua a pilha
//     destruir_pilha(p);
//     printf("\n\nSucesso! Pilha destruida.\n");
//
//     return 0;
//

int main() {
    // 2. Instancie uma fila
    fila_t* f = criar_fila();

    // 3. Insira dez números inteiros na fila
    printf("Enfileirando: ");
    for (int i = 1; i <= 10; i++) {
        int valor = i * 10;
        printf("%d ", valor);
        enfileirar(f, valor);
    }

    // 4. Imprima o inicio da fila e o tamanho da fila
    printf("\n\nInicio da fila: %d", inicio(f));
    printf("\nTamanho da fila: %d", tamanho_fila(f));

    // 5. Remova três números da fila (Saem os primeiros: 10, 20, 30)
    printf("\n\nRemovendo 3 elementos... ");
    for (int i = 0; i < 3; i++) {
        printf("Saiu: %d | ", desenfileirar(f));
    }

    // 6. Imprima todos os números da fila (esvaziando-a)
    printf("\nElementos restantes na fila: ");
    while (!fila_vazia(f)) {
        printf("%d ", desenfileirar(f));
    }

    // 7. Destrua a fila
    destruir_fila(f);
    printf("\n\nSucesso! Fila destruida.\n");

    return 0;
}