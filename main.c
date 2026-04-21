#include <stdio.h>
#include "libprg/libprg.h"

int main() {
    // 2. Instancie uma pilha
    pilha_t* p = criar_pilha();

    // 3. Insira dez números inteiros na pilha
    printf("Empilhando: ");
    for (int i = 1; i <= 10; i++) {
        int valor = i * 10;
        printf("%d ", valor);
        empilhar(p, valor);
    }

    // 4. Imprima o topo da pilha e o tamanho da pilha
    printf("\n\nTopo atual: %d", topo(p));
    printf("\nTamanho da pilha: %d", tamanho_pilha(p));

    // 5. Remova três números da pilha
    printf("\n\nDesempilhando 3 elementos...");
    for (int i = 0; i < 3; i++) {
        desempilhar(p);
    }

    // 6. Imprima todos os números da pilha (esvaziando-a)
    printf("\nElementos restantes na pilha: ");
    while (!pilha_vazia(p)) {
        printf("%d ", desempilhar(p));
    }

    // 7. Destrua a pilha
    destruir_pilha(p);
    printf("\n\nSucesso! Pilha destruida.\n");

    return 0;
}