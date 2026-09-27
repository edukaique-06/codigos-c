#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *A, int n) {
    for (int i = 1; i < n; i++) {
        int chave = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > chave) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = chave;
    }
}

void imprimir_vetor(int *vetor, int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

int main() {
    int n;

    printf("Digite o tamanho do vetor: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Erro: Tamanho invalido fornecido.\n");
        return 1;
    }

    int *vetor = (int *)malloc((size_t)n * sizeof(int));

    if (!vetor) {
        printf("Erro: Falha na alocacao de memoria.\n");
        return 1;
    }

    printf("Digite os %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &vetor[i]) != 1) {
            printf("Erro na leitura do elemento %d.\n", i);
            free(vetor);
            return 1;
        }
    }

    printf("\nVetor original:\n");
    imprimir_vetor(vetor, n);

    insertion_sort(vetor, n);

    printf("\nVetor ordenado:\n");
    imprimir_vetor(vetor, n);

    free(vetor);
}
