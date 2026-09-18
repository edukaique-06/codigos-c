#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

typedef struct {
    uint8_t *buffer;
    size_t capacidade;
    size_t deslocamento;
} Arena;

Arena criar_arena(size_t capacidade) {
    Arena arena;
    arena.buffer = (uint8_t *)malloc(capacidade);
    arena.capacidade = capacidade;
    arena.deslocamento = 0;
    return arena;
}

void *arena_alocar(Arena *arena, size_t tamanho, size_t alinhamento) {
    uintptr_t ponteiro_atual = (uintptr_t)(arena->buffer + arena->deslocamento);
    uintptr_t ponteiro_alinhado = (ponteiro_atual + (alinhamento - 1)) & ~(alinhamento - 1);
    size_t novo_deslocamento = (size_t)(ponteiro_alinhado - (uintptr_t)arena->buffer) + tamanho;

    if (novo_deslocamento > arena->capacidade) {
        return NULL;
    }

    arena->deslocamento = novo_deslocamento;
    return (void *)ponteiro_alinhado;
}

void arena_resetar(Arena *arena) {
    arena->deslocamento = 0;
}

void arena_destruir(Arena *arena) {
    free(arena->buffer);
    arena->buffer = NULL;
    arena->capacidade = 0;
    arena->deslocamento = 0;
}

int main() {
    Arena arena = criar_arena(1024);

    int *vetor_int = (int *)arena_alocar(&arena, 5 * sizeof(int), _Alignof(int));
    for (int i = 0; i < 5; i++) {
        vetor_int[i] = (i + 1) * 7;
    }

    double *vetor_double = (double *)arena_alocar(&arena, 3 * sizeof(double), _Alignof(double));
    for (int i = 0; i < 3; i++) {
        vetor_double[i] = (i + 1) * 3.1415;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor_int[i]);
    }
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("%.2f ", vetor_double[i]);
    }
    printf("\n");

    printf("Bytes usados: %zu de %zu\n", arena.deslocamento, arena.capacidade);

    arena_resetar(&arena);

    int *novo_bloco = (int *)arena_alocar(&arena, 2 * sizeof(int), _Alignof(int));
    novo_bloco[0] = 99;
    novo_bloco[1] = 100;

    printf("%d %d\n", novo_bloco[0], novo_bloco[1]);
    printf("Bytes usados apos reset: %zu\n", arena.deslocamento);

    arena_destruir(&arena);
}
