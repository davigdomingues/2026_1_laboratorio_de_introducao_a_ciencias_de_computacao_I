#include <stdio.h>

int main() {
    int n; // n: número de valores
    scanf("%d", &n);

    int valores[n]; // array de valores
    for (int i = 0; i < n; i++) scanf("%d", &valores[i]);

    long long soma = 0;
    for (int i = 0; i < (n + 1) / 2; i++) soma += (long long)valores[i] * valores[n - 1 - i]; // soma os valores dos elementos do array

    printf("%lld", soma);
    return 0;
}