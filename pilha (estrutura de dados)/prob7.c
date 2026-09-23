#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
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
    return c;
}

int main()
{
    char *expressaooriginal = malloc(200 * sizeof(char));
    fgets(expressaooriginal, 200, stdin);
    expressaooriginal[strcspn(expressaooriginal, "\n")] = '\0';

    int tamanho = strlen(expressaooriginal);
    Pilha *p = CriarPilha(tamanho);

    char limpa[200];
    int indice = 0;

    for (int i = 0; i < tamanho; i++)
    {
        char c = expressaooriginal[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c >= 'A' && c <= 'Z')
            {
                c = c + 32;
            }
            limpa[indice] = c;
            indice++;
        }
    }
    limpa[indice] = '\0';

    for (int i = 0; i < indice; i++)
    {
        Push(p, limpa[i]);
    }

    int eh_palindromo = 1;
    for (int i = 0; i < indice; i++)
    {
        char c = Pop(p);
        if (limpa[i] != c)
        {
            eh_palindromo = 0;
            break;
        }
    }

    if (eh_palindromo)
    {
        printf("Verdadeiro\n");
    }
    else
    {
        printf("Falso\n");
    }

    free(p->pilha);
    free(p);
    free(expressaooriginal);
}
