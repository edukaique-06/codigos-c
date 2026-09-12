#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef bool (*FiltroFn)(int);

void adicionar_elemento(int **vetor, size_t *tamanho, int valor) {
    size_t novo_tamanho = *tamanho + 1;
    
    int *temp = (int *)realloc(*vetor, novo_tamanho * sizeof(int));
    if (!temp) {
        printf("Erro: falha ao alocar memoria para adicionar elemento.\n");
        free(*vetor);
        exit(EXIT_FAILURE);
    }

    *vetor = temp;
    *(*vetor + *tamanho) = valor;
    *tamanho = novo_tamanho;
}

int* filtrar(const int *vetor, size_t tamanho, FiltroFn condicao, size_t *tam_saida) {
    *tam_saida = 0;
    int *resultado = NULL;

    const int *ptr = vetor;
    const int *fim = vetor + tamanho;

    for (; ptr < fim; ptr++) {
        if (condicao(*ptr)) {
            int *temp = (int *)realloc(resultado, (*tam_saida + 1) * sizeof(int));
            if (!temp) {
                printf("Erro: falha ao alocar memoria durante a filtragem.\n");
                free(resultado);
                exit(EXIT_FAILURE);
            }
            resultado = temp;
            *(resultado + *tam_saida) = *ptr;
            (*tam_saida)++;
        }
    }

    return resultado;
}

bool eh_par(int n) { return n % 2 == 0; }
bool maior_que_dez(int n) { return n > 10; }

int main(void) {
    int *dados = NULL;
    size_t tamanho = 0;
    int qtd = 0;

    printf("Quantos elementos deseja inserir? ");
    if (scanf("%d", &qtd) != 1 || qtd <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    for (int i = 0; i < qtd; i++) {
        int valor;
        printf("Digite o elemento %d: ", i + 1);
        if (scanf("%d", &valor) != 1) {
            printf("Entrada invalida.\n");
            free(dados);
            return 1;
        }
        adicionar_elemento(&dados, &tamanho, valor);
    }

    printf("\nArray inserido (%zu itens):\n", tamanho);
    for (size_t i = 0; i < tamanho; i++) {
        printf("%d ", *(dados + i));
    }
    printf("\n\n");

    size_t tam_pares = 0;
    int *pares = filtrar(dados, tamanho, eh_par, &tam_pares);

    printf("Filtro [eh_par] (%zu itens):\n", tam_pares);
    for (size_t i = 0; i < tam_pares; i++) {
        printf("%d ", *(pares + i));
    }
    printf("\n\n");

    size_t tam_maiores = 0;
    int *maiores = filtrar(dados, tamanho, maior_que_dez, &tam_maiores);

    printf("Filtro [maior_que_dez] (%zu itens):\n", tam_maiores);
    for (size_t i = 0; i < tam_maiores; i++) {
        printf("%d ", *(maiores + i));
    }
    printf("\n");

    free(dados);
    free(pares);
    free(maiores);

    return 0;
}
