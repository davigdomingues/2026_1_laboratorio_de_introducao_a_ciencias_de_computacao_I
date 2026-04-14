#include <stdio.h>

int main() {
    int numero1, numero2, numero3, maior;
    
    scanf("%d %d %d", &numero1, &numero2, &numero3);
    
    if (numero1 == numero2 || numero1 == numero3 || numero2 == numero3)
        printf ("Ha numeros iguais");
        
    else if (numero1 > numero2 && numero1 > numero3)
        printf("%d", numero1);
        
    else if (numero2 > numero1 && numero2 > numero3)
        printf("%d", numero2);
        
    else
        printf("%d", numero3);
    
    return 0;
}