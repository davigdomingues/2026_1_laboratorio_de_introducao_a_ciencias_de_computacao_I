#include <stdio.h>

int main() {
    int n; // tamanho do array
    scanf("%d", &n);

    int b[1000], k[1000]; // arrays para armazenar os valores de b e k

    for (int i = 0; i < n; i++) // loop para ler os valores de b
        scanf("%d", &b[i]);

    for (int i = 0; i < n; i++)
        k[i] = b[i] + (i > 0 ? b[i - 1] : 0) + (i < n - 1 ? b[i + 1] : 0);

    for (int i = 0; i < n; i++)
        printf("%d%c", k[i], i < n - 1 ? ' ' : '\n'); // imprime o valor de k[i]

    return 0;
}