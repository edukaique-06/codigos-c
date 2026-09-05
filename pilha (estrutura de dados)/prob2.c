#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *pilha;
    int tam;
    int topo;
    int qntd;
}Pilha;

Pilha *CriarPilha(int tam)
{
    Pilha *p;
    p = malloc(sizeof(Pilha));
    p->pilha = malloc(tam * sizeof(int));
    p->tam = tam;
    p->topo = -1;
    p->qntd = 0;
    return p;
}

void Push(Pilha *p,int num)
{
    if(p == NULL)
    {
        printf("Lista Inexistente\n");
    }
    else
    {
        if(p->qntd == p->tam)
        {
            printf("Stack Overflow\n");
        }
        else
        {
            p->topo++;
            p->pilha[p->topo] = num;
            p->qntd++;
        }
    }
}
void PrintBinary(Pilha *p)
{
    while(p->topo >= 0)
    {
        printf("%d", p->pilha[p->topo]);
        p->topo--;
    }
}

int main()
{
    Pilha *p;
    int decimal;

    printf("Digite um numero decimal: ");
    scanf("%d", &decimal);

    p = CriarPilha(32); //Limite perfeito para ser usado com numeros binários, pois qualquer numero decimal de tipo int tera em binario no máximo 32 dígitos

    while(decimal > 0)
    {
        Push(p, decimal % 2); //Função recebe o resto da divisão, que é o valor que precisamos (0 ou 1)
         decimal = decimal / 2; //Decimal recebe o quociente da divisão atual, para ser usado na próxima divisão
    }

    printf("Numero em binario: ");
    PrintBinary(p);

    free(p->pilha);
    free(p);
}
