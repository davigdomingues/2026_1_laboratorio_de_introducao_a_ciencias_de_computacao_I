#include <stdio.h>

int main()
{
    float preco = 0.0;
    scanf("%f", &preco);
    
    if (preco > 100) {
        printf("%.2f", preco*0.9);
        return 0;
    }
    
    printf("%.2f", preco);

    return 0;
}