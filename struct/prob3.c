#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definicao da struct para representar um país
typedef struct {
    char nome[105];
    int ouro;
    int prata;
    int bronze;
} Pais;

// Funcao de comparacao para o qsort
int compararPaises(const void *a, const void *b) {
    Pais *p1 = (Pais *)a;
    Pais *p2 = (Pais *)b;

    // 1. Criterio: Mais medalhas de ouro
    if (p1->ouro != p2->ouro) {
        return p2->ouro - p1->ouro; // Decrescente
    }

    // 2. Criterio: Mais medalhas de prata
    if (p1->prata != p2->prata) {
        return p2->prata - p1->prata; // Decrescente
    }

    // 3. Criterio: Mais medalhas de bronze
    if (p1->bronze != p2->bronze) {
        return p2->bronze - p1->bronze; // Decrescente
    }

    // 4. Criterio: Ordem alfabetica do nome
    return strcmp(p1->nome, p2->nome); // Crescente
}

int main() {
    int n;

    if (scanf("%d", &n) != 1) return 0;

    Pais quadro[n];

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", quadro[i].nome, &quadro[i].ouro, &quadro[i].prata, &quadro[i].bronze);
    }

    // Ordena o vetor de structs
    qsort(quadro, n, sizeof(Pais), compararPaises);

    // Impressao do resultado
    for (int i = 0; i < n; i++) {
        printf("%s %d %d %d\n", quadro[i].nome, quadro[i].ouro, quadro[i].prata, quadro[i].bronze);
    }
}
