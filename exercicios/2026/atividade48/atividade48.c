#include <stdio.h>

int main() {
    int n, m; // variáveis para armazenar o tamanho dos arrays crescente e decrescente
    scanf("%d %d", &n, &m);

    int crescente[n], decrescente[m]; // arrays para armazenar os valores crescentes e decrescentes respectivamente

    for (int i = 0; i < n; i++) scanf("%d", &crescente[i]);
    for (int i = 0; i < m; i++) scanf("%d", &decrescente[i]);

    int i = 0, j = m - 1, k = 0, total = n + m, valor = 0; // variáveis para controlar o índice dos arrays e a quantidade total de elementos e o valor atual

    while (i < n && j >= 0) {
        if (crescente[i] <= decrescente[j])
            valor = crescente[i++];
        
        else
            valor = decrescente[j--];

        printf("%d%c", valor, ++k < total ? ' ' : '\n'); // imprime o valor e o caractere de nova linha se o índice k for menor que o total, caso contrário imprime o caractere de nova linha
    }

    while (i < n) {
        printf("%d%c", crescente[i], ++k < total ? ' ' : '\n'); // imprime o valor e o caractere de nova linha se o índice k for menor que o total, caso contrário imprime o caractere de nova linha
        i++;
    }

    while (j >= 0) {
        printf("%d%c", decrescente[j], ++k < total ? ' ' : '\n'); // mesmo que o while anterior, mas para o array decrescente
        j--;
    }

    return 0;
}