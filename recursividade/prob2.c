#include <stdio.h>

int potencia(int base, int expoente) {
    if (expoente == 0) {
        return 1;
    }
    return base * potencia(base, expoente - 1);
}

int main() {
    int base = 2;
    int exp = 5;

    int resultado = potencia(base, exp);

    printf("%d elevado a %d = %d\n", base, exp, resultado);
}
