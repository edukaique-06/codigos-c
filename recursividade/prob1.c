#include <stdio.h>

void ordenar(int *v, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int busca_binaria_rec(int *v, int inicio, int fim, int chave) {
    if (inicio > fim) {
        return -1;
    }

    int meio = inicio + (fim - inicio) / 2;

    if (v[meio] == chave) {
        return meio;
    }

    if (chave < v[meio]) {
        return busca_binaria_rec(v, inicio, meio - 1, chave);
    }

    return busca_binaria_rec(v, meio + 1, fim, chave);
}

int main() {
    int n, chave, i;
    int vetor[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    scanf("%d", &chave);

    ordenar(vetor, n);

    int pos = busca_binaria_rec(vetor, 0, n - 1, chave);

    printf("%d\n", pos);
}
