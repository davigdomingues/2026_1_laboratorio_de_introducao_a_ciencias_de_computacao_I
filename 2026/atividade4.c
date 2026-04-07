#include <stdio.h>

int main()
{
    float nota1, nota2, media = 0.0;
    
    scanf("%f %f", &nota1, & nota2);
    
    media = (nota1 + nota2)/2;
    
    if (media >= 8) printf("Aprovado");
    else printf("Reprovado");

    return 0;
}