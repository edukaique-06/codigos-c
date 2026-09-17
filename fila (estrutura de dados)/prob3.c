#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *fila;
    int tam;
    int qntd;
    int inicio;
    int fim;
}FilaCircular;

FilaCircular *CriarFila(int tam)
{
    FilaCircular *f = malloc(sizeof(FilaCircular));
    f->fila = malloc(tam * sizeof(int));
    f->tam = tam;
    f->qntd = 0;
    f->inicio = 0;
    f->fim = 0;

    return f;
}

void Push(FilaCircular *f, int valor)
{
    if(f == NULL)
    {
        printf("Fila circular inexistente\n");
    }
    else
    {
        if(f->qntd == f->tam)
        {
            printf("Fila circular cheia\n");
        }
        else
        {
            f->fila[f->fim] = valor;
            f->fim = (f->fim + 1) % f->tam;
            f->qntd++;
        }
    }
}

int Pop(FilaCircular *f)
{
    if(f == NULL)
    {
        printf("Fila circular inexistente\n");
    }
    else
    {
        if(f->qntd == 0)
        {
            return -1;
        }
        else
        {
            int retirado = f->fila[f->inicio];
            f->inicio = (f->inicio + 1) % f->tam;
            f->qntd--;

            return retirado;
        }
    }
}

void ImprimirFila(FilaCircular *f)
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
            int idx = (f->inicio + i) % f->tam;
            printf("%d ", f->fila[idx]);
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

    FilaCircular *f = CriarFila(tam);

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
                    printf("Fila circular vazia\n");
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
