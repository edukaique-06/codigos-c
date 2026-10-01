#include <stdio.h>
#include <stdlib.h>

int resolver(int m, int *blocos, int n_blocos, int *memo) {
    if (m == 0) {
        return 0;
    }
    if (m < 0) {
        return 1000000000;
    }
    if (memo[m] != -1) {
        return memo[m];
    }

    int menor = 1000000000;
    for (int i = 0; i < n_blocos; i++) {
        if (m >= blocos[i]) {
            int res = resolver(m - blocos[i], blocos, n_blocos, memo);
            if (res != 1000000000) {
                if (res + 1 < menor) {
                    menor = res + 1;
                }
            }
        }
    }

    memo[m] = menor;
    return memo[m];
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n_blocos, m;
        scanf("%d %d", &n_blocos, &m);

        int *blocos = (int *)malloc(n_blocos * sizeof(int));
        for (int i = 0; i < n_blocos; i++) {
            scanf("%d", &blocos[i]);
        }

        int *memo = (int *)malloc((m + 1) * sizeof(int));
        for (int i = 0; i <= m; i++) {
            memo[i] = -1;
        }

        printf("%d\n", resolver(m, blocos, n_blocos, memo));

        free(blocos);
        free(memo);
    }
}
