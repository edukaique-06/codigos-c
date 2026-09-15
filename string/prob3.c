#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *comprimir_rle(const char *origem) {
    if (!origem) return NULL;

    size_t capacidade = 16;
    size_t tamanho = 0;
    char *destino = malloc(capacidade);
    if (!destino) return NULL;

    size_t i = 0;
    size_t len = strlen(origem);

    while (i < len) {
        char atual = origem[i];
        int contagem = 0;

        while (i < len && origem[i] == atual) {
            contagem++;
            i++;
        }

        char temp[32];
        int escritos = snprintf(temp, sizeof(temp), "%c%d", atual, contagem);

        while (tamanho + escritos + 1 > capacidade) {
            capacidade *= 2;
            char *novo = realloc(destino, capacidade);
            if (!novo) {
                free(destino);
                return NULL;
            }
            destino = novo;
        }

        memcpy(destino + tamanho, temp, escritos);
        tamanho += escritos;
    }

    destino[tamanho] = '\0';
    return destino;
}

char *descomprimir_rle(const char *origem) {
    if (!origem) return NULL;

    size_t capacidade = 16;
    size_t tamanho = 0;
    char *destino = malloc(capacidade);
    if (!destino) return NULL;

    size_t i = 0;
    size_t len = strlen(origem);

    while (i < len) {
        char c = origem[i++];

        if (i >= len || !isdigit((unsigned char)origem[i])) {
            free(destino);
            return NULL;
        }

        int contagem = 0;
        while (i < len && isdigit((unsigned char)origem[i])) {
            contagem = contagem * 10 + (origem[i] - '0');
            i++;
        }

        while (tamanho + contagem + 1 > capacidade) {
            capacidade = (capacidade * 2 > tamanho + contagem + 1) ? capacidade * 2 : tamanho + contagem + 1;
            char *novo = realloc(destino, capacidade);
            if (!novo) {
                free(destino);
                return NULL;
            }
            destino = novo;
        }

        memset(destino + tamanho, c, contagem);
        tamanho += contagem;
    }

    destino[tamanho] = '\0';
    return destino;
}

int main(void) {
    const char *texto_original = "WWWWWWAAAAAABBBCCCDDDDDDDDD";

    printf("Original:     %s\n", texto_original);

    char *comprimido = comprimir_rle(texto_original);
    if (!comprimido) {
        printf("Falha na alocação da compressão.\n");
        return 1;
    }
    printf("Comprimido:   %s\n", comprimido);

    char *restaurado = descomprimir_rle(comprimido);
    if (restaurado) {
        printf("Restaurado:   %s\n", restaurado);
        free(restaurado);
    } else {
        printf("Erro ao descomprimir.\n");
    }

    free(comprimido);
}
