#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, delta, raiz1, raiz2;
    scanf("%lf %lf %lf", &a, &b, &c);

    delta = b*b - 4*a*c;
    
    if (delta < 0) {
        printf("Não há raízes reais.");
        return 0;
    }

    raiz1 = ((-1)*b - sqrt(delta))/(2*a);
    
    if (delta == 0) {
        printf("Raiz: %.3lf", raiz1);
        return 0;
    }

    raiz2 =((-1)*b + sqrt(delta))/(2*a);
    
    printf("Raízes: %.3lf %.3lf", raiz1, raiz2);

    return 0;
}