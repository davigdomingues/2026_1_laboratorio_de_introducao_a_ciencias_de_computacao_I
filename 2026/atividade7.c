#include <stdio.h>

int main()
{
    float lado1 = 0.0, lado2 = 0.0, lado3 = 0.0;
    scanf("%f %f %f", &lado1, &lado2, &lado3);
    
    if (lado1 + lado2 <= lado3 || lado1 + lado3 <= lado2 || lado2 + lado3 <= lado1) printf("Triangulo Invalido");
    else printf("Triangulo Valido");

    return 0;
}
