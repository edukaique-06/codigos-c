#include <stdio.h>
#include <stdbool.h>

bool casar(const char *padrao, const char *texto) {
    if (*padrao == '\0' && *texto == '\0') {
        return true;
    }

    if (*padrao == '*' && *(padrao + 1) != '\0' && *texto == '\0') {
        return false;
    }

    if (*padrao == '?' || *padrao == *texto) {
        return casar(padrao + 1, texto + 1);
    }

    if (*padrao == '*') {
        return casar(padrao + 1, texto) || (*texto != '\0' && casar(padrao, texto + 1));
    }

    return false;
}

int main() {
    char texto[] = "recursividade";
    char p1[] = "rec*s?v*de";
    char p2[] = "rec*x";

    printf("%s -> %s: %s\n", texto, p1, casar(p1, texto) ? "true" : "false");
    printf("%s -> %s: %s\n", texto, p2, casar(p2, texto) ? "true" : "false");
}
