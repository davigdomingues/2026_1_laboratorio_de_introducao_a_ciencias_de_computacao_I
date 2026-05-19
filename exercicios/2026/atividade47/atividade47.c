#include <stdio.h>

int main() {
    int n, c; // n: número de moedas, c: valor do troco
    scanf("%d %d", &n, &c);

    int moedas[n]; // array de moedas
    for (int i = 0; i < n; i++) scanf("%d", &moedas[i]);

    int esquerda = 0, direita = n - 1;
    while (esquerda < direita) { // loop para encontrar as moedas que somam o valor c
        int soma = moedas[esquerda] + moedas[direita]; // soma das moedas nas posições esquerda e direita
        if (soma == c) { // se a soma das moedas nas posições esquerda e direita for igual ao valor c, imprime as moedas e retorna 0
            printf("%d %d\n", moedas[esquerda], moedas[direita]);
            return 0;
        } 
        
        else if (soma < c) // se a soma das moedas nas posições esquerda e direita for menor do que o valor c, incrementa a posição esquerda
            esquerda++;

        else // se a soma das moedas nas posições esquerda e direita for maior do que o valor c, decrementa a posição direita
            direita--;
    }

    printf("Sem troco exato");
    return 0;
}