#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int *pilha;
    int tamanho;
    int topo;
    int qntd;
} Pilha;

Pilha *CriarPilha(int tam)
{
    Pilha *p;
    p = malloc(sizeof(Pilha));
    p->pilha = malloc(tam * sizeof(int));
    p->tamanho = tam;
    p->topo = -1;
    p->qntd = 0; 

    return p;
}

void Push(Pilha *p, char tag)
{
    if(p == NULL)
    {
        printf("Pilha Inexistente\n");
    }
    else
    {
        if(p->qntd == p->tamanho)
        {
            printf("Stack Overflow\n");
        }
        else
        {
            p->topo++;
            p->pilha[p->topo] = tag;
            p->qntd++;
        }
    }
}

char Pop(Pilha *p)
{
    char c;

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
    char *html = malloc(100 * sizeof(char));
    fgets(html, 100, stdin);
    html[strcspn(html, "\n")] = '\0';

    int tamanhopilha = strlen(html);
    Pilha *p = CriarPilha(tamanhopilha);

    int i;
    int valido = 1;

    for(i = 0; i < tamanhopilha; i++)
    {
        if(html[i] == '<')
        {
            if(html[i + 1] == '/')
            {
                char tagFechamento = html[i + 2];
                
                if(p->qntd == 0)
                {
                    valido = 0;
                    break;
                }
                
                char tagAberta = Pop(p);
                if(tagAberta != tagFechamento)
                {
                    valido = 0;
                    break;
                }
            }
            else
            {
                char tagAbertura = html[i + 1];
                Push(p, tagAbertura);
            }
        }
    }

    if(valido && p->qntd == 0)
    {
        printf("Valido\n");
    }
    else
    {
        printf("Invalido\n");
    }

    free(p->pilha);
    free(p);
    free(html);
}
