#include <stdio.h>

/*
    NOTA DE COMPARAÇÃO:
    Este programa é ligeiramente menos eficiente que 'atividade6_alternativo.c'.
    1. Múltiplas chamadas de scanf aumentam o overhead de função.
    2. O uso de 'float' tem menos precisão que 'double'.
    3. Múltiplos 'if's sequenciais criam mais instruções de desvio (branches) do que a abordagem aninhada otimizada.
*/

float min4(float a, float b, float c, float d) { // função para encontrar o menor entre quatro números
    float min = a; // assume inicialmente que o primeiro número é o menor

    if (b < min) // verifica se o segundo número é menor que o atual mínimo
        min = b;

    if (c < min) // verifica se o terceiro número é menor que o atual mínimo
        min = c;

    if (d < min) // verifica se o quarto número é menor que o atual mínimo
        min = d;

    return min; // retorna o menor número encontrado
}

int main() {
    float num1, num2, num3, num4; // números a serem informados pelo usuário
    float mediaDescarte; // variável para armazenar a média dos números, dado o descarte do menor valor

    if (scanf("%f", &num1) != 1 || scanf("%f", &num2) != 1 || scanf("%f", &num3) != 1 || scanf("%f", &num4) != 1) // verifica se a leitura dos números foi bem-sucedida
        return 1;

    mediaDescarte = (num1 + num2 + num3 + num4 - min4(num1, num2, num3, num4 )) / 3; // calcula a média dos números, descartando o menor valor
    printf("A média dos números é: %f\n", mediaDescarte); // imprime a média com duas casas decimais
    
    return 0;
}