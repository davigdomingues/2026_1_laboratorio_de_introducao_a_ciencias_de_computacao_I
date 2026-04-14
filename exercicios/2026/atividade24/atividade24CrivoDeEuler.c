#include <stdio.h>
#include <stdlib.h>

// implementação: Crivo de Euler - O(n)
int contar_primos(int n) {
    if (n < 2) return 0;
    
    int *menor_fator = calloc(n + 1, sizeof(int)); // Aloca memória para o menor fator primo de cada número
    int *primos = malloc((n / 2 + 1) * sizeof(int)); // Primos até N são aproximadamente n/log(n), então n/2 é seguro e largo.

    if (!menor_fator || !primos) { // falha na alocação de memória
        free(menor_fator);
        free(primos);
        return -1;
    }

    int total_primos = 0, p;

    for (int i = 2; i <= n; ++i) {
        if (menor_fator[i] == 0) {
            menor_fator[i] = i;
            primos[total_primos++] = i;
        }

        for (int j = 0; j < total_primos; ++j) {
            p = primos[j];
            if (p > menor_fator[i] || (long long)i * p > n) break;
            menor_fator[i * p] = p;
        }
    }

    free(menor_fator);
    free(primos);
    return total_primos;
}

int main() {
    int n, resultado;
    scanf("%d", &n);

    resultado = contar_primos(n);

    if (resultado == -1) {
        fprintf(stderr, "Erro: Falha na alocação de memória.\n");
        return 1;
    }

    printf("%d\n", resultado);
    return 0;
}