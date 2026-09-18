#include <stdio.h>
#include <stddef.h>

typedef int (*Comparador)(const void *, const void *);
typedef void (*Operacao)(void *);

void ordenar(void *base, size_t n, size_t tamanho, Comparador cmp) {
    char *dados = (char *)base;
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            char *elem1 = dados + j * tamanho;
            char *elem2 = dados + (j + 1) * tamanho;
            if (cmp(elem1, elem2) > 0) {
                for (size_t k = 0; k < tamanho; k++) {
                    char temp = elem1[k];
                    elem1[k] = elem2[k];
                    elem2[k] = temp;
                }
            }
        }
    }
}

void mapear(void *base, size_t n, size_t tamanho, Operacao op) {
    char *dados = (char *)base;
    for (size_t i = 0; i < n; i++) {
        op(dados + i * tamanho);
    }
}

int comparar_inteiros(const void *a, const void *b) {
    int val_a = *(const int *)a;
    int val_b = *(const int *)b;
    return val_a - val_b;
}

void dobrar_inteiro(void *elem) {
    int *val = (int *)elem;
    *val *= 2;
}

void imprimir_inteiro(void *elem) {
    printf("%d ", *(int *)elem);
}

int main() {
    int dados[] = {42, 13, 89, 7, 25, 64};
    size_t n = sizeof(dados) / sizeof(dados[0]);

    ordenar(dados, n, sizeof(int), comparar_inteiros);
    mapear(dados, n, sizeof(int), dobrar_inteiro);
    mapear(dados, n, sizeof(int), imprimir_inteiro);
    printf("\n");
}
