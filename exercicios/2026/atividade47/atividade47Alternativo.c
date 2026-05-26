#include <stdio.h>

int main() {
    int n, c; // n: número de moedas, c: valor do troco
    scanf("%d %d", &n, &c);

    int moedas[n]; // array de moedas
    for (int i = 0; i < n; i++) scanf("%d", &moedas[i]);

    int *esq = moedas; // ponteiro para o início
    int *dir = moedas + n - 1; // ponteiro para o fim

    while (esq < dir) { // dois ponteiros caminhando sobre o vetor, um a partir do início e outro a partir do fim
        int soma = *esq + *dir;

        if (soma == c) {
            printf("%d %d\n", *esq, *dir);
            return 0;
        }

        if (soma < c) esq++; // se a soma for menor que c, avança para a próxima moeda
        else dir--; // se a soma for maior que c, recua para a próxima moeda
    }

    printf("Sem troco exato.");
    return 0;
}