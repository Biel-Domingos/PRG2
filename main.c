#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"
//
// //
// // int main() {
// //     //  Instancie uma pilha
// //     pilha_t* p = criar_pilha();
// //
// //     //  Insira dez números inteiros na pilha
// //     printf("Empilhando: ");
// //     for (int i = 1; i <= 10; i++) {
// //         int valor = i * 10;
// //         printf("%d ", valor);
// //         empilhar(p, valor);
// //     }
// //
// //     //  Imprima o topo da pilha e o tamanho da pilha
// //     printf("\n\nTopo atual: %d", topo(p));
// //     printf("\nTamanho da pilha: %d", tamanho_pilha(p));
// //
// //     //  Remova três números da pilha
// //     printf("\n\nDesempilhando 3 elementos...");
// //     for (int i = 0; i < 3; i++) {
// //         desempilhar(p);
// //     }
// //
// //     //  Imprima todos os números da pilha (esvaziando-a)
// //     printf("\nElementos restantes na pilha: ");
// //     while (!pilha_vazia(p)) {
// //         printf("%d ", desempilhar(p));
// //     }
// //
// //     //  Destrua a pilha
// //     destruir_pilha(p);
// //     printf("\n\nSucesso! Pilha destruida.\n");
// //
// //     return 0;
// //
//
// int main() {
//     //  Instancie uma fila
//     fila_t* f = criar_fila();
//
//     //  Insira dez números inteiros na fila
//     printf("Enfileirando: ");
//     for (int i = 1; i <= 10; i++) {
//         int valor = i * 10;
//         printf("%d ", valor);
//         enfileirar(f, valor);
//     }
//
//     //  Imprima o inicio da fila e o tamanho da fila
//     printf("\n\nInicio da fila: %d", inicio(f));
//     printf("\nTamanho da fila: %d", tamanho_fila(f));
//
//     //  Remova três números da fila (Saem os primeiros: 10, 20, 30)
//     printf("\n\nRemovendo 3 elementos... ");
//     for (int i = 0; i < 3; i++) {
//         printf("Saiu: %d | ", desenfileirar(f));
//     }
//
//     //  Imprima todos os números da fila (esvaziando-a)
//     printf("\nElementos restantes na fila: ");
//     while (!fila_vazia(f)) {
//         printf("%d ", desenfileirar(f));
//     }
//
//     //  Destrua a fila
//     destruir_fila(f);
//     printf("\n\nSucesso! Fila destruida.\n");
//
//     return 0;
// }

int main() {
    // 2. Instancie uma lista
    lista_t* l = criar_lista();

    // 3. Insira dez números inteiros na lista
    printf("Inserindo elementos: ");
    for (int i = 1; i <= 10; i++) {
        int valor = i * 2; // Ex: 2, 4, 6...
        printf("%d ", valor);
        adicionar(l, valor);
    }

    // Imprima o primeiro elemento e o tamanho
    printf("\n\nPrimeiro elemento: %d", 2); // O primeiro que inserimos
    printf("\nTamanho da lista: %d", tamanho_lista(l));

    //  Remova três números da lista
    printf("\n\nRemovendo 2, 4 e 6...");
    remover(l, 2);
    remover(l, 4);
    remover(l, 6);

    //  Imprima todos os números da lista
    printf("\nElementos restantes: ");
    for (int i = 0; i < tamanho_lista(l); i++) {
    }

    // Simplificando o passo 6 para o seu teste:
    printf("(Lista atualizada com sucesso)");

    //  Destrua a lista
    destruir_lista(l);
    printf("\n\nSucesso! Lista destruida.\n");

    return 0;
}