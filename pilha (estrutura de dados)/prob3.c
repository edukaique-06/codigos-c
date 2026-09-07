#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *pilha;
    int tamanho;
    int topo;
    int qntd;
} Pilha;

Pilha *CriarPilha(int tam)
{
    Pilha *p;
    p = malloc(sizeof(Pilha));
    p->pilha = malloc(tam * sizeof(char));
    p->tamanho = tam;
    p->topo = -1;
    p->qntd = 0;

    return p;
}

void Push(Pilha *p, char caracter)
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
            p->pilha[p->topo] = caracter;
            p->qntd++;
        }
    }
}

char Pop(Pilha *p)
{
    char c = '\0';
    if(p == NULL)
    {
        printf("Pilha Inexistente\n");
    }
    else
    {
        if(p->qntd == 0)
        {
            printf("Stack Underflow\n");
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
    char *expressaooriginal = malloc(100 * sizeof(char));
    fgets(expressaooriginal, 100, stdin);
    expressaooriginal[strcspn(expressaooriginal, "\n")] = '\0';

    int tamanhopilha = strlen(expressaooriginal);
    Pilha *p = CriarPilha(tamanhopilha);

    char expressaoinvertida[tamanhopilha + 1];
    int i;
    int aux = 0;

    for (i = tamanhopilha - 1; i >= 0; i--)
    {
        if (expressaooriginal[i] == '(')
        {
            expressaoinvertida[aux] = ')';
        }
        else
        {
            if (expressaooriginal[i] == ')')
            {
                expressaoinvertida[aux] = '(';
            }
            else
            {
                expressaoinvertida[aux] = expressaooriginal[i];
            }
        }
        aux++;
    }
    expressaoinvertida[aux] = '\0';

    char expressaoposfixa[tamanhopilha + 1];
    int j = 0;

    for (i = 0; i < aux; i++)
    {
        if (expressaoinvertida[i] == '(')
        {
            Push(p, '(');
        }
        else
        {
            if (expressaoinvertida[i] == ')')
            {
                while (p->topo != -1 && p->pilha[p->topo] != '(')
                {
                    expressaoposfixa[j] = Pop(p);
                    j++;
                }
                Pop(p);
            }
            else
            {
                if (expressaoinvertida[i] == '^')
                {
                    while (p->topo != -1 && p->pilha[p->topo] == '^')
                    {
                        expressaoposfixa[j] = Pop(p);
                        j++;
                    }
                    Push(p, expressaoinvertida[i]);
                }
                else
                {
                    if (expressaoinvertida[i] == '*' || expressaoinvertida[i] == '/')
                    {
                        while (p->topo != -1 && p->pilha[p->topo] == '^')
                        {
                            expressaoposfixa[j] = Pop(p);
                            j++;
                        }
                        Push(p, expressaoinvertida[i]);
                    }
                    else
                    {
                        if (expressaoinvertida[i] == '+' || expressaoinvertida[i] == '-')
                        {
                            while (p->topo != -1 && (p->pilha[p->topo] == '^' || p->pilha[p->topo] == '*' || p->pilha[p->topo] == '/'))
                            {
                                expressaoposfixa[j] = Pop(p);
                                j++;
                            }
                            Push(p, expressaoinvertida[i]);
                        }
                        else
                        {
                            expressaoposfixa[j] = expressaoinvertida[i];
                            j++;
                        }
                    }
                }
            }
        }
    }

    while (p->topo != -1)
    {
        expressaoposfixa[j] = Pop(p);
        j++;
    }
    expressaoposfixa[j] = '\0';

    char expressaoprefixa[tamanhopilha + 1];
    int m = 0;
    for (i = j - 1; i >= 0; i--)
    {
        expressaoprefixa[m] = expressaoposfixa[i];
        m++;
    }
    expressaoprefixa[m] = '\0';

    printf("%s\n", expressaoprefixa);

    free(p->pilha);
    free(p);
    free(expressaooriginal);
} 
