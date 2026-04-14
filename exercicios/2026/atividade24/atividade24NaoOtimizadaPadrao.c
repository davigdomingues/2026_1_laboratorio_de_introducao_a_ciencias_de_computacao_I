#include <stdio.h>

int main() {
    int numero, totalPrimos = 0;
    scanf("%d", &numero);

    for (int i = 2; i <= numero; i++) {
        int contador = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                contador++;
            }
        }
        if (contador == 2) {
            totalPrimos++;
        }
    }

    printf("%d", totalPrimos);
    return 0;
}