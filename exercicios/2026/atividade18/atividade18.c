#include <stdio.h>

int main() {
    int tipo;
    float massa;
    
    scanf("%d %f", &tipo, &massa);
    float massaTotal1menosDe500T = 100 + 10*massa;
    
    switch (tipo) {
        case 1:
            if (massa <= 500) printf("Tarifa: %.2f", massaTotal1menosDe500T);
            else printf("Tarifa: %.2f", massaTotal1menosDe500T*1.2);
            break;
            
        case 2:
            if (massa <= 100) printf("Tarifa: 50.00");
            else printf("Tarifa: 60.00");
            break;
            
        case 3:
            printf("Tarifa: 0.00");
            break;
            
        default:
            printf("Opção inválida");
    }

    return 0;
}
