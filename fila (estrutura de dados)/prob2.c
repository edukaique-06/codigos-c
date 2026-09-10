#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int prioridade; // Maior número = maior prioridade
    int tempo_exec; // Tempo em segundos/ciclos
} Tarefa;

typedef struct {
    Tarefa *fila;
    int qntd;
    int tamanho;
} FilaTarefas;

FilaTarefas *CriarFila(int tamInicial) {
    FilaTarefas *f = (FilaTarefas *)malloc(sizeof(FilaTarefas));
    f->fila = (Tarefa *)malloc(tamInicial * sizeof(Tarefa));
    f->qntd = 0;
    f->tamanho = tamInicial;
    return f;
}

// Desafio 1: Redimensionamento automático caso atinja a capacidade máxima
void RedimensionarSeCheio(FilaTarefas *f) {
    if (f->qntd == f->tamanho) {
        f->tamanho *= 2;
        f->fila = (Tarefa *)realloc(f->fila, f->tamanho * sizeof(Tarefa));
        printf("\n[Sistema] Fila cheia! Capacidade expandida para %d slots.\n", f->tamanho);
    }
}

// Desafio 2: Inserção linear ordenada por prioridade (mantendo estabilidade FIFO para prioridades iguais)
void InserirTarefa(FilaTarefas *f, Tarefa nova) {
    if (f == NULL) return;

    RedimensionarSeCheio(f);

    // Encontra a posição: tarefas com maior prioridade ficam mais à frente (índices menores)
    int pos = 0;
    while (pos < f->qntd && f->fila[pos].prioridade >= nova.prioridade) {
        pos++;
    }

    // Desloca os elementos para a direita para abrir espaço na posição encontrada
    for (int i = f->qntd; i > pos; i--) {
        f->fila[i] = f->fila[i - 1];
    }

    f->fila[pos] = nova;
    f->qntd++;
    printf("Tarefa ID %d adicionada na posicao %d.\n", nova.id, pos);
}

// Remoção linear idêntica ao seu código original, mas com a correção do bug de estouro de memória
int ProcessarProximaTarefa(FilaTarefas *f, Tarefa *tarefaExecutada) {
    if (f == NULL || f->qntd == 0) {
        return 0; // Fila vazia
    }

    *tarefaExecutada = f->fila[0];

    // Deslocamento para a esquerda: f->qntd - 1 evita acessar memória além do limite
    for (int i = 0; i < f->qntd - 1; i++) {
        f->fila[i] = f->fila[i + 1];
    }

    f->qntd--;
    return 1; // Sucesso
}

void ImprimirFila(FilaTarefas *f) {
    if (f == NULL || f->qntd == 0) {
        printf("\nFila vazia!\n");
        return;
    }

    printf("\n--- Estado Atual da Fila (Total: %d/%d) ---\n", f->qntd, f->tamanho);
    printf("Pos | ID   | Prioridade | Tempo de Execucao\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < f->qntd; i++) {
        printf("%-3d | %-4d | %-10d | %d s\n", 
               i, f->fila[i].id, f->fila[i].prioridade, f->fila[i].tempo_exec);
    }
}

void DestruirFila(FilaTarefas *f) {
    if (f != NULL) {
        free(f->fila);
        free(f);
    }
}

int main() {
    int tamInicial = 2; // Tamanho pequeno de teste para demonstrar a expansão dinâmica
    FilaTarefas *fila = CriarFila(tamInicial);
    int op;

    do {
        printf("\n1 - Adicionar Tarefa\n");
        printf("2 - Executar Proxima Tarefa\n");
        printf("3 - Listar Fila\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        if (op == 1) {
            Tarefa t;
            printf("ID: ");
            scanf("%d", &t.id);
            printf("Prioridade (ex: 1 a 10): ");
            scanf("%d", &t.prioridade);
            printf("Tempo estimado (s): ");
            scanf("%d", &t.tempo_exec);

            InserirTarefa(fila, t);
        } 
        else if (op == 2) {
            Tarefa t;
            if (ProcessarProximaTarefa(fila, &t)) {
                printf("\n[Executando] ID: %d | Prioridade: %d | Tempo: %ds\n", 
                       t.id, t.prioridade, t.tempo_exec);
            } else {
                printf("\nFila Vazia! Nada a executar.\n");
            }
        } 
        else if (op == 3) {
            ImprimirFila(fila);
        }

    } while (op != 0);

    DestruirFila(fila);
}
