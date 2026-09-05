#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *pilha;
    int tam;
    int qntd;
    int topo;
} Pilha;

Pilha  *criarpilha(int tam)
{
    Pilha *p;
    p = malloc(sizeof(Pilha));
    p->pilha = malloc(tam * sizeof(int));
    p->tam = tam;
    p->qntd = 0;
    p->topo = -1;
    return p;
}

void push(Pilha *p, int num)
{
    if(p == NULL)
    {
        printf("Pilha Inexistente\n");
    }
    else
    {
        if(p->qntd == p->tam)
        {
            printf("Stack Overflow\n");
            return;
        }
        else
        {
            p->topo++;
            p->pilha[p->topo] = num;
            p->qntd++;
        }
    }
}

int pop(Pilha *p)
{
    int numeroretirado;
    if(p == NULL)
    {
        printf("Pilha Inexistente\n");
        return -1;
    }
    else
    {
        if(p->qntd == 0)
        {
            return -2;
        }
        else
        {
            // Forma explícita - numeroretirado = (*((p->pilha)+(P->topo)));
            numeroretirado = p->pilha[p->topo]; //Forma implícita
            p->topo--;
            p->qntd--;
            return numeroretirado;
        }
    }
}

void ImprimirPilha(Pilha *p)
{
    if(p == NULL)
    {
        printf("Pilha Inexistente\n");
    }
    else
    {
        int i;
        for(i = p->topo ; i>= 0; i--)
        {
            printf("%d\n",p->pilha[i]);
        }
        printf("\n");
    }
}

int menupilha()
{
    printf("1 - Empilhar\n");
    printf("2 - Desempilhar\n");
    printf("3 - Imprimir pilha\n");
    printf("0 - Sair\n");
    printf("Digite a opcao: ");
    int op;
    scanf("%d",&op);
    return op;
}

int main()
{
    int tam;
    int num;
    int retirado;
    int qntd = 0;

    printf("Digite o tamanho da pilha: ");
    scanf("%d",&tam);

    Pilha *p = criarpilha(tam);
    int op = menupilha();

    while(op != 0)
    {
        if(op == 1)
        {
            printf("Digite o numero que deseja empilhar: ");
            scanf("%d",&num);
            push(p,num);
        }
        else
        {
            if(op == 2)
            {
                retirado = pop(p);
                if(retirado == -2)
                {
                    printf("Stack Underflow\n");
                }
                else
                {
                    printf("Numero retirado da pilha: %d\n",retirado);
                }
            }
            else
            {
                if(op == 3)
                {
                    ImprimirPilha(p);
                }
            }
        }
        op = menupilha();
    }
    free(p->pilha);
    free(p);
}
