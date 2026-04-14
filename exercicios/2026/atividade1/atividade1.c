#include <stdio.h>

int main() {
    int numero1, numero2;
    
    scanf("%d %d", &numero1, &numero2);
    
    if (numero1 > numero2) {
        printf("%d", numero1);
    }
        
    else if (numero2 > numero1) {
        printf("%d", numero2);
    }
        
    else {
        printf("igual");
    }
    
    return 0;
}