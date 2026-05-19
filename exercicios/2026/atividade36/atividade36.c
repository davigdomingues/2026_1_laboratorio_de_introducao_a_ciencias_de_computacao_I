#include <stdio.h>

int main() {
    int n, c; // n: número de moedas, c: valor do troco
    scanf("%d %d", &n, &c);

    int moedas[n]; // array de moedas
    for (int i = 0; i < n; i++) scanf("%d", &moedas[i]);

    int esquerda = 0, direita = n - 1;
    while (esquerda < direita) 
        if ((moedas[esquerda] + moedas[direita]) == c) { // se a soma das moedas nas posições esquerda e direita for igual ao valor c, imprime as moedas e retorna 0
            printf("%d %d\n", moedas[esquerda], moedas[direita]);
            return 0;
        }
        
        else // se a soma das moedas nas posições esquerda e direita for diferente do valor c, decrementa a posição direita
            --direita;

    printf("Sem troco exato");
    return 0;
}