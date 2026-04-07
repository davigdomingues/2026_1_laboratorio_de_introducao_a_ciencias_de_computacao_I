#include <stdio.h>

int main()
{
    int numero;
    scanf("%d", &numero);
    
    if (numero % 5 == 0 && numero % 3 != 0) printf("Divisivel por 5");
    
    else if (numero % 5 != 0 && numero % 3 == 0) printf("Divisivel por 3");
    
    else if (numero % 15 == 0) printf("Divisivel por 5 e 3");
    
    else printf("Nao e divisivel por 3 nem por 5");

    return 0;
}
