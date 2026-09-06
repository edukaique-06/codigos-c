#include <stdio.h>
#include <stdlib.h>

void separar_pares_impares(int *origem, int tamanho, 
                           int **pares, int *tam_pares, 
                           int **impares, int *tam_impares) {
    *tam_pares = 0;
    *tam_impares = 0;

    *pares = (int *)malloc(tamanho * sizeof(int));
    *impares = (int *)malloc(tamanho * sizeof(int));

    if (*pares == NULL || *impares == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    int *fim = origem + tamanho;
    for (int *p = origem; p < fim; p++) {
        if (*p % 2 == 0) {
            *(*pares + *tam_pares) = *p;
            (*tam_pares)++;
        } else {
            *(*impares + *tam_impares) = *p;
            (*tam_impares)++;
        }
    }
}

int main() {
    int dados[] = {12, 7, 19, 4, 22, 15, 8, 31, 10};
    int n = sizeof(dados) / sizeof(dados[0]);

    int *vetor_pares = NULL;
    int *vetor_impares = NULL;
    int qtd_pares = 0, qtd_impares = 0;

    separar_pares_impares(dados, n, &vetor_pares, &qtd_pares, &vetor_impares, &qtd_impares);

    printf("Array original (%d itens):\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", *(dados + i));
    }

    printf("\n\nPares (%d itens):\n", qtd_pares);
    for (int i = 0; i < qtd_pares; i++) {
        printf("%d ", *(vetor_pares + i));
    }

    printf("\n\nÍmpares (%d itens):\n", qtd_impares);
    for (int i = 0; i < qtd_impares; i++) {
        printf("%d ", *(vetor_impares + i));
    }
    printf("\n");

    free(vetor_pares);
    free(vetor_impares);
    vetor_pares = NULL;
    vetor_impares = NULL;
}
