#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[105];
    char cor[15];
    char tamanho;
} Camiseta;

// Funcao auxiliar para mapear o tamanho (P, M, G) em valores numericos
// para que G > M > P fique facil de ordenar decrescente
int valorTamanho(char t) {
    if (t == 'P') return 1;
    if (t == 'M') return 2;
    if (t == 'G') return 3;
    return 0;
}

int compararCamisetas(const void *a, const void *b) {
    const Camiseta *c1 = (const Camiseta *)a;
    const Camiseta *c2 = (const Camiseta *)b;

    // 1. Criterio: Cor em ordem alfabetica crescente (branco antes de vermelho)
    int cmpCor = strcmp(c1->cor, c2->cor);
    if (cmpCor != 0) {
        return cmpCor;
    }

    // 2. Criterio: Tamanho decrescente (G > M > P)
    int v1 = valorTamanho(c1->tamanho);
    int v2 = valorTamanho(c2->tamanho);
    if (v1 != v2) {
        return v2 - v1; // Decrescente
    }

    // 3. Criterio: Nome em ordem alfabetica crescente
    return strcmp(c1->nome, c2->nome);
}

int main() {
    int n;
    int primeiroCaso = 1;

    while (scanf("%d", &n) == 1 && n != 0) {
        // Linha em branco entre casos de teste sucessivos
        if (!primeiroCaso) {
            printf("\n");
        }
        primeiroCaso = 0;

        Camiseta lista[n];

        for (int i = 0; i < n; i++) {
            // Le o nome (que pode conter espacos)
            scanf(" %[^\r\n]", lista[i].nome);
            // Le a cor e o tamanho
            scanf("%s %c", lista[i].cor, &lista[i].tamanho);
        }

        // Ordenacao do vetor de structs
        qsort(lista, n, sizeof(Camiseta), compararCamisetas);

        // Impressao formatada
        for (int i = 0; i < n; i++) {
            printf("%s %c %s\n", lista[i].cor, lista[i].tamanho, lista[i].nome);
        }
    }
}
