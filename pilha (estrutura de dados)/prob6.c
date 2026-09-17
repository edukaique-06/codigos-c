#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **pilha;
    int tamanho;
    int topo;
    int qntd;
} Pilha;

Pilha *CriarPilha(int tam)
{
    Pilha *p;
    p = malloc(sizeof(Pilha));
    p->pilha = malloc(tam * sizeof(char *));
    p->tamanho = tam;
    p->topo = -1;
    p->qntd = 0;

    return p;
}

void Push(Pilha *p, char *caracter)
{
    if (p == NULL)
    {
        printf("Pilha Inexistente\n");
    }
    else
    {
        if (p->qntd == p->tamanho)
        {
            printf("Stack Overflow\n");
        }
        else
        {
            p->topo++;
            p->pilha[p->topo] = strdup(caracter);
            p->qntd++;
        }
    }
}

char *Pop(Pilha *p)
{
    char *c = NULL;
    if(p == NULL)
    {
        printf("Pilha Inexistente\n");
        return NULL;
    }
    else
    {
        if(p->qntd == 0)
        {
            printf("Stack Underflow\n");
            return NULL;
        }
        else
        {
            c = p->pilha[p->topo];
            p->topo--;
            p->qntd--;
            return c;
        }
    }
}

int main()
{
    char *expressaoprefixa = malloc(100 * sizeof(char));
    fgets(expressaoprefixa, 100, stdin);
    expressaoprefixa[strcspn(expressaoprefixa, "\n")] = '\0';

    int tamanhopilha = strlen(expressaoprefixa);
    Pilha *p = CriarPilha(tamanhopilha);

    int i;
    for (i = tamanhopilha - 1; i >= 0; i--)
    {
        char c = expressaoprefixa[i];

        if (c == ' ' || c == '\t')
        {
            continue;
        }

        if (c != '+' && c != '-' && c != '*' && c != '/' && c != '^')
        {
            char operando[2] = {c, '\0'};
            Push(p, operando);
        }
        else
        {
            char *op1 = Pop(p);
            char *op2 = Pop(p);

            if (op1 != NULL && op2 != NULL)
            {
                int novoTamanho = strlen(op1) + strlen(op2) + 4;
                char *expressaoTemp = malloc(novoTamanho * sizeof(char));

                strcpy(expressaoTemp, "(");
                strcat(expressaoTemp, op1);

                char operador_str[2] = {c, '\0'};
                strcat(expressaoTemp, operador_str);

                strcat(expressaoTemp, op2);
                strcat(expressaoTemp, ")");

                Push(p, expressaoTemp);

                free(expressaoTemp);
                free(op1);
                free(op2);
            }
        }
    }

    char *expressaoinfixa = Pop(p);

    if (expressaoinfixa != NULL)
    {
        printf("%s\n", expressaoinfixa);
        free(expressaoinfixa);
    }

    free(p->pilha);
    free(p);
    free(expressaoprefixa);
}
