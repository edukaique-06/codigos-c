#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int matricula;
    char nome[64];
    Data nascimento;
    float notas[3];
    float media;
} Aluno;

void calcular_media(Aluno *a) {
    float soma = 0.0f;
    for (int i = 0; i < 3; i++) {
        soma += a->notas[i];
    }
    a->media = soma / 3.0f;
}

void cadastrar_aluno(Aluno *a, int matricula, const char *entrada_nome, Data nasc, float n1, float n2, float n3) {
    a->matricula = matricula;
    strncpy(a->nome, entrada_nome, sizeof(a->nome) - 1);
    a->nome[sizeof(a->nome) - 1] = '\0';
    a->nome[strcspn(a->nome, "\n")] = '\0';
    a->nascimento = nasc;
    a->notas[0] = n1;
    a->notas[1] = n2;
    a->notas[2] = n3;
    calcular_media(a);
}

void imprimir_aluno(const Aluno *a) {
    printf("-------------------------------------------\n");
    printf("Matricula:  %d\n", a->matricula);
    printf("Nome:       %s\n", a->nome);
    printf("Nascimento: %02d/%02d/%04d\n", a->nascimento.dia, a->nascimento.mes, a->nascimento.ano);
    printf("Notas:      %.1f | %.1f | %.1f\n", a->notas[0], a->notas[1], a->notas[2]);
    printf("Media:      %.2f (%s)\n", a->media, (a->media >= 7.0f) ? "Aprovado" : "Reprovado");
}

int main() {
    int total_alunos = 2;
    char buffer[128];

    Aluno *turma = (Aluno *) malloc(total_alunos * sizeof(Aluno));
    if (turma == NULL) {
        return 1;
    }

    for (int i = 0; i < total_alunos; i++) {
        int mat;
        Data d;
        float n1, n2, n3;

        printf("Matricula do aluno %d: ", i + 1);
        scanf("%d", &mat);
        getchar();

        printf("Nome do aluno %d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);

        printf("Data de nascimento (dd mm aaaa): ");
        scanf("%d %d %d", &d.dia, &d.mes, &d.ano);

        printf("3 notas: ");
        scanf("%f %f %f", &n1, &n2, &n3);
        getchar();

        cadastrar_aluno(&turma[i], mat, buffer, d, n1, n2, n3);
    }

    printf("\n=== RELATORIO DA TURMA ===\n");
    for (int i = 0; i < total_alunos; i++) {
        imprimir_aluno(&turma[i]);
    }
    printf("-------------------------------------------\n");

    free(turma);
    turma = NULL;

    return 0;
}
