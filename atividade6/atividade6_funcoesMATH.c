#include <stdio.h>
#include <math.h> // necessário para fminf

int main() {
    float num1, num2, num3, num4; // números a serem informados pelo usuário
    float mediaDescarte; // variável para armazenar a média dos números, dado o descarte do menor valor

    if (scanf("%f", &num1) != 1 || scanf("%f", &num2) != 1 || scanf("%f", &num3) != 1 || scanf("%f", &num4) != 1) // verifica se a leitura dos números foi bem-sucedida
        return 1;

    mediaDescarte = (num1 + num2 + num3 + num4 - fminf(num1, fminf(num2, fminf(num3, num4)))) / 3; // calcula a média dos números, descartando o menor valor
    printf("A média dos números é: %f\n", mediaDescarte); // imprime a média com duas casas decimais
    
    return 0;
}