#include <stdio.h>
#include <math.h>

int main() {
    int numero = 0, somaTernaria = 0;
    int i;
    
    scanf("%d", &numero);
    
    for (i = 0; numero > 0; i++) {
        somaTernaria += ((numero % 10) * (int)pow(3,i));
        numero /= 10;
    }

    printf("%d", somaTernaria);
    return 0;
}
