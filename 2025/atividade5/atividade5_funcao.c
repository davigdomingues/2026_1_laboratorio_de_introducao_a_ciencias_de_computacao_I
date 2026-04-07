#include <stdio.h>

static int max(int a, int b) { // função para encontrar o maior entre dois números
    return (a > b) ? a : b; // retorna a se a for maior que b, caso contrário retorna b
}

int main() {
    int num1, num2, num3; // números a serem comparados

    if (scanf("%d", &num1) != 1 || scanf("%d", &num2) != 1 || scanf("%d", &num3) != 1) // verifica se a leitura dos números foi bem-sucedida
        return 1;

    printf("%d\n", max(num1, max(num2, num3))); // chama a função max para encontrar o maior número entre os três e imprime o resultado

    return 0;
}