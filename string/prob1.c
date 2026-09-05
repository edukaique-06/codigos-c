#include <stdio.h>
#include <string.h>

char para_minusculo(char c) 
{
    if (c >= 'A' && c <= 'Z') 
    {
        return c + 32;
    }
    return c;
}

void limpar_quebra_linha(char *str) 
{
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n')
    {
        str[tam - 1] = '\0';
    }
}

void inverter_string(char *origem, char *destino) 
{
    int tam = strlen(origem);
    int i;
    for (i = 0; i < tam; i++)
      {
        destino[i] = origem[tam - 1 - i];
    }
    destino[tam] = '\0';
}

int eh_palindromo(char *str) 
{
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) 
    {
        if (para_minusculo(str[i]) != para_minusculo(str[j])) 
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main() 
{
    char texto[200];
    char invertida[200];

    fgets(texto, sizeof(texto), stdin);
    limpar_quebra_linha(texto);

    inverter_string(texto, invertida);

    printf("%lu\n", strlen(texto));
    printf("%s\n", invertida);
    printf("%d\n", eh_palindromo(texto));
}
