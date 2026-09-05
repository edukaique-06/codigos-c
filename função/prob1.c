#include <stdio.h>

void motor(int v[],int qntd)
{
    int i;
    int posicao;
    int valor = 0;
    
    for(i=1;i<qntd;i++)
    {
        posicao = 0;
        if(v[i]<v[i - 1])
        {
            posicao = i + 1;
            break;
        }
    }
    printf("%d\n",posicao);
}

int main()
{
    int qntd,i;
    scanf("%d",&qntd);
    
    int v[qntd];
    for(i=0;i<qntd;i++)
    {
        scanf("%d",&v[i]);
    }

    motor(v,qntd);
}
