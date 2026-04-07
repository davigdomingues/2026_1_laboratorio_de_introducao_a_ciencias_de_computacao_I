#include <stdio.h>
#include <math.h>

int main() {
    float peso = 0.0, altura, IMC = 0.0;
    scanf("%f %f", &peso, &altura);
    
    IMC = peso/(altura*altura);
    
    if (IMC >= 30) printf("Obesidade");
    else if (IMC >= 25) printf("Sobrepeso");
    else if (IMC >= 18.5) printf("Peso normal");
    else printf("Abaixo do peso");
}