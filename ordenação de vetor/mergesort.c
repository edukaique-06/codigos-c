#include <stdio.h>
#include <stdlib.h>

void merge(int *A, int inicio, int meio, int fim, int *aux) {
    int i = inicio;
    int j = meio + 1;
    int k = inicio;

    while (i <= meio && j <= fim) {
        if (A[i] <= A[j]) {
            aux[k++] = A[i++];
        } else {
            aux[k++] = A[j++];
        }
    }

    while (i <= meio) {
        aux[k++] = A[i++];
    }

    while (j <= fim) {
        aux[k++] = A[j++];
    }

    for (i = inicio; i <= fim; i++) {
        A[i] = aux[i];
    }
}

void merge_sort(int *A, int inicio, int fim, int *aux) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        merge_sort(A, inicio, meio, aux);
        merge_sort(A, meio + 1, fim, aux);
        merge(A, inicio, meio, fim, aux);
    }
}

void imprimir_vetor(int *vetor, int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

int main(void) {
    int n;

    printf("Digite o tamanho do vetor: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Erro: Tamanho invalido fornecido.\n");
        return 1;
    }

    int *vetor = (int *)malloc((size_t)n * sizeof(int));
    int *aux = (int *)malloc((size_t)n * sizeof(int));

    if (!vetor || !aux) {
        printf("Erro: Falha na alocacao de memoria.\n");
        free(vetor);
        free(aux);
        return 1;
    }

    printf("Digite os %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &vetor[i]) != 1) {
            printf("Erro na leitura do elemento %d.\n", i);
            free(vetor);
            free(aux);
            return 1;
        }
    }

    printf("\nVetor original:\n");
    imprimir_vetor(vetor, n);

    merge_sort(vetor, 0, n - 1, aux);

    printf("\nVetor ordenado:\n");
    imprimir_vetor(vetor, n);

    free(vetor);
    free(aux);
}
