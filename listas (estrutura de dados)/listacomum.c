#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *lista;
    int tam;
    int qntd;
}Lista;

Lista *CriarLista(int tam)
{
    Lista *l = malloc(sizeof(Lista));
    l->lista = malloc(tam * sizeof(int));
    l->tam = tam;
    l->qntd = 0;

    return l;
}

int Push(Lista *l,int valor, int posicaovetor)
{
    if(l == NULL)
    {
        printf("Lista inexistente\n");
        return 0;
    }
    if(l->qntd == l->tam)
    {
        printf("Lista cheia\n");
        return 0;
    }
    if(posicaovetor < 0 || posicaovetor > l->qntd)
    {
        printf("Posicao invalida\n");
        return 0;
    }

    int i;
    
    for(i = l->qntd - 1; i >= posicaovetor; i--)
    {
        l->lista[i + 1] = l->lista[i];
    }
    l->lista[posicaovetor] = valor;
    l->qntd++;

    return 1;
}

int PopwithP(Lista *l, int posicaovetor)
{
    if(l == NULL)
    {
        printf("Lista inexistente\n");
        return 0;
    }
    if(l->qntd == 0)
    {
        printf("Lista vazia\n");
        return 0;
    }
    if(posicaovetor < 0 || posicaovetor >= l->qntd)
    {
        printf("Posicao invalida\n");
        return 0;
    }

    int retirado = l->lista[posicaovetor];
    int i;

    for(i = posicaovetor; i < l->qntd - 1; i++)
    {
        l->lista[i] = l->lista[i + 1];
    }
    l->qntd--;
    return retirado;
}

int PopWithE(Lista *l, int elementovetor)
{
    if(l == NULL)
    {
        printf("Lista inexistente\n");
        return 0;
    }
    if(l->qntd == 0)
    {
        printf("Lista vazia\n");
        return 0;
    }
    int posicao = -1;
    int i;

    for(i = 0; i< l->qntd; i++)
    {
        if(l->lista[i] == elementovetor)
        {
            posicao = i;
            break;
        }
    }
    if(posicao == -1)
    {
        printf("Elemento nao encontrado\n");
        return 0;
    }
    
    int retirado = l->lista[posicao];

    int j;
    for(j = posicao; j < l->qntd - 1; j++)
    {
        l->lista[j] = l->lista[j + 1];
    }
    
    l->qntd--;
    return retirado;
}

void ImprimirLista(Lista *l)
{
    if (l == NULL || l->lista == NULL)
    {
        printf("Lista inexistente\n");
    }
    else if (l->qntd == 0)
    {
        printf("Lista vazia\n");
    }
    else
    {
        for (int i = 0; i < l->qntd; i++)
        {
            printf("%d ", l->lista[i]);
        }
        printf("\n");
    }
}

int main()
{
    int tam;
    printf("Digite o tamanho maximo da lista: ");
    scanf("%d", &tam);

    Lista *l = CriarLista(tam);

    int opcao = 1;
    int valor, pos, removido;

    while (opcao != 0)
    {
        printf("\n1 - Inserir elemento (Push)\n");
        printf("2 - Remover por posicao (PopwithP)\n");
        printf("3 - Remover por valor (PopWithE)\n");
        printf("4 - Imprimir lista\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            printf("Digite o valor: ");
            scanf("%d", &valor);
            printf("Digite a posicao (0 a %d): ", l->qntd);
            scanf("%d", &pos);
            if (Push(l, valor, pos))
            {
                printf("Inserido com sucesso!\n");
            }
        }
        else if (opcao == 2)
        {
            printf("Digite a posicao a remover: ");
            scanf("%d", &pos);
            removido = PopwithP(l, pos);
            if (removido != -1)
            {
                printf("Elemento removido: %d\n", removido);
            }
        }
        else if (opcao == 3)
        {
            printf("Digite o valor que deseja remover: ");
            scanf("%d", &valor);
            removido = PopWithE(l, valor);
            if (removido != -1)
            {
                printf("Elemento removido: %d\n", removido);
            }
        }
        else if (opcao == 4)
        {
            ImprimirLista(l);
        }
    }
    free(l->lista);
    free(l);
}
