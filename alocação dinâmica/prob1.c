#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *vetor;

    scanf("%d", &n);

    vetor = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
}
