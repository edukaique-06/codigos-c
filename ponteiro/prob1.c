#include <stdio.h>

void trocar(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);

    trocar(&x, &y);
    printf("%d %d\n", x, y);
}
