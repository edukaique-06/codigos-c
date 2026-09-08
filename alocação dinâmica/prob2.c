#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **dados;
    int linhas;
    int colunas;
} Matriz;

Matriz* criar_matriz(int linhas, int colunas) {
    Matriz *m = (Matriz*) malloc(sizeof(Matriz));
    m->linhas = linhas;
    m->colunas = colunas;

    m->dados = (int**) malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        m->dados[i] = (int*) calloc(colunas, sizeof(int));
    }

    return m;
}

void preencher_matriz(Matriz *m) {
    int valor = 1;
    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            if (m->dados[i][j] == 0) {
                m->dados[i][j] = valor++;
            }
        }
    }
}

void imprimir_matriz(Matriz *m) {
    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            printf("%3d ", m->dados[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void expandir_linhas(Matriz *m, int novas_linhas) {
    m->dados = (int**) realloc(m->dados, novas_linhas * sizeof(int*));

    for (int i = m->linhas; i < novas_linhas; i++) {
        m->dados[i] = (int*) calloc(m->colunas, sizeof(int));
    }

    m->linhas = novas_linhas;
}

void liberar_matriz(Matriz *m) {
    for (int i = 0; i < m->linhas; i++) {
        free(m->dados[i]);
    }
    free(m->dados);
    free(m);
}

int main() {
    Matriz *mat = criar_matriz(2, 3);

    preencher_matriz(mat);
    imprimir_matriz(mat);

    expandir_linhas(mat, 4);
    preencher_matriz(mat);
    imprimir_matriz(mat);

    liberar_matriz(mat);
}
