#include <stdio.h>

typedef struct 
{
    int id;
    char nome[50];
    float nota1;
    float nota2;
    float media;
} Aluno;

float calcular_media(float n1, float n2) 
{
    return (n1 + n2) / 2.0;
}

void ordenar_alunos(Aluno *alunos, int n) 
{
    int i, j;
    Aluno temp;

    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (alunos[j].media < alunos[j + 1].media) 
            {
                temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    Aluno alunos[50];

    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        scanf("%d %s %f %f", &alunos[i].id, alunos[i].nome, &alunos[i].nota1, &alunos[i].nota2);
        alunos[i].media = calcular_media(alunos[i].nota1, alunos[i].nota2);
    }

    ordenar_alunos(alunos, n);

    for (i = 0; i < n; i++)
    {
        printf("%d %s %.2f\n", alunos[i].id, alunos[i].nome, alunos[i].media);
    }
}
