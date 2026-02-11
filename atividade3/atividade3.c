#include <stdio.h>

int main() {
    int numero; // variável para armazenar o número digitado pelo usuário

    if (scanf("%d", &numero) == 1) // lê o número digitado pelo usuário
        printf("%d\n", numero * 2); // imprime o número digitado pelo usuário multiplicado por 2

    return 0;
}