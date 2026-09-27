#include <stdio.h>
#include <stdlib.h>

int particionar(int *A, int p, int r) {
    int pivo = A[r];
    int i = p - 1;
    int j;
    int temp;

    for (j = p; j < r; j++) {
        if (A[j] <= pivo) {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;

    return i + 1;
}

void quick_sort(int *A, int p, int r) {
    int q;

    if (p < r) {
        q = particionar(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}

void imprimir_vetor(int *vetor, int n) {
    int i;
    printf("[ ");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

int main() {
    int n;
    int i;
    int *vetor;

    printf("Digite o tamanho do vetor: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Erro: Tamanho invalido fornecido.\n");
        return 1;
    }

    vetor = (int *)malloc(n * sizeof(int));
    if (!vetor) {
        printf("Erro: Falha na alocacao de memoria.\n");
        return 1;
    }

    printf("Digite os %d elementos:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &vetor[i]) != 1) {
            printf("Erro na leitura do elemento %d.\n", i);
            free(vetor);
            return 1;
        }
    }

    printf("\nVetor original:\n");
    imprimir_vetor(vetor, n);

    quick_sort(vetor, 0, n - 1);

    printf("\nVetor ordenado:\n");
    imprimir_vetor(vetor, n);

    free(vetor);
}
