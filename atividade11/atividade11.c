#include <stdio.h>

int main() {
    int tesouro; // variável para armazenar o valor do tesouro
    if (scanf("%d", &tesouro) != 1)
        return 0;

    int *p = &tesouro; // ponteiro para acessar o valor do tesouro
    printf("Valor inicial do tesouro : %d\n", *p);

    printf("Valor do tesouro usando mapa : %d\n", *p);
    *p = *p + 10; // adiciona 10 moedas ao valor do tesouro usando o ponteiro
    printf(
        "Valor do tesouro usando mapa depois de adicionarmos 10 moedas : %d\n",
        *p
    );

    int **pp = &p; // ponteiro para ponteiro para acessar o valor do tesouro usando um mapa para o mapa
    printf("Valor do tesouro usando mapa para o mapa : %d\n", **pp);
    **pp = **pp + 10; // adiciona mais 10 moedas ao valor do tesouro usando o ponteiro para ponteiro
    printf(
        "Valor do tesouro usando mapa para o mapa depois de adicionarmos 10 moedas : %d\n",
        **pp
    );

    return 0;
}