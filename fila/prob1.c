#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *fila;
    int qntd;
    int tamanho;
}Fila;

Fila *CriarFila(int tam)
{
    Fila *f = malloc(sizeof(Fila));
    f->fila = malloc(tam * sizeof(int));
    f->qntd = 0;
    f->tamanho = tam;

    return f;
}

void Push(Fila *f, int valor)
{
    if(f == NULL)
    {
        printf("Fila Inexistente\n");
    }
    else
    {
        if(f->qntd == f->tamanho)
        {
            printf("Fila Cheia\n");
        }
        else
        {
            f->fila[f->qntd] = valor;
            f->qntd++;
        }
    }
}

int Pop(Fila *f)
{
    if(f == NULL)
    {
        printf("Fila Inexistente\n");
    }
    else
    {
        if(f->qntd == 0)
        {
            return -1;
        }
        else
        {
            int i;
            int retirado = f->fila[0];

            for(i = 0; i < f->qntd ; i++)
            {
                f->fila[i] = f->fila[i + 1];
            }
            f->qntd--;
            return retirado;
        }
    }
}

void ImprimirFila(Fila *f)
{
    if(f == NULL)
    {
        printf("Fila Inexistente\n");
    }
    else
    {
        int i;
        for(i = 0; i < f->qntd;i++)
        {
            printf("%d ",f->fila[i]);
        }
        printf("\n");
    }
}

int MenuFila()
{
    printf("1 - Inserir valor\n");
    printf("2 - Retirar valor\n");
    printf("3 - Imprimir fila\n");
    printf("0 - Sair\n");
    printf("Digite a opcao: ");
    int op;
    scanf("%d",&op);
    return op;
}

int main()
{
    int tam;
    printf("Digite o tamanho da fila: ");
    scanf("%d",&tam);

    Fila *f = CriarFila(tam);

    int op = MenuFila();

    while(op != 0)
    {
        if(op == 1)
        {
            int valor;
            printf("Digite um valor: ");
            scanf("%d",&valor);
            Push(f,valor);
        }
        else
        {
            if(op == 2)
            {
                int valorretirado = Pop(f);
                if(valorretirado == -1)
                {
                    printf("Fila Vazia\n");
                }
                else
                {
                    printf("Valor retirado: %d\n",valorretirado);
                }
            }
            else
            {
                if(op == 3)
                {
                    ImprimirFila(f);
                }
            }
        }
        op = MenuFila();
    }
    free(f->fila);
    free(f);
}
