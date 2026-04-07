#include <stdio.h>

int main() {
    int esquerda, direita;
    scanf("%d %d", &esquerda, &direita);
    
    if (esquerda == direita) printf("Empate");
    
    /* uso de aritmética modular:
       pedra vence tesoura, que vence papel, que vence pedra (3 opções)
       a escolha anterior vence a seguinte, ou seja, se tudo fosse "sequencial"
       para a casa esquerda ganhar, então direita = esquerda + 1, dentro do
       intervalo de "escolhas"
    */
    else if ((esquerda+1)%3 == direita) printf("Esquerda");
    else printf("Direita");

    return 0;
}