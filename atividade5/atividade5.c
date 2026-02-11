#include <stdio.h>

int main() {
    int num1, num2, num3; // números a serem comparados

    if (scanf("%d", &num1) != 1 || scanf("%d", &num2) != 1 || scanf("%d", &num3) != 1) // lê os números e verifica sucesso
        return 1;

    if (num1 >= num2 && num1 >= num3) // verifica se o primeiro número é o maior
        printf("%d\n", num1);

    else if (num2 >= num1 && num2 >= num3) // verifica se o segundo número é o maior
        printf("%d\n", num2);

    else // se o terceiro número for o maior ou se houver empate, imprime o terceiro número
        printf("%d\n", num3);

    return 0;
}