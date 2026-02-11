#include <stdio.h>
#include <math.h> // necessário para pow, sqrt, fmin e fmax

int main() {
    int a, b, c; // coeficientes inteiros conforme especificado no enunciado

    if (scanf("%d %d %d", &a, &b, &c) != 3) // lê três números inteiros
        return 1;

    double delta = pow(b, 2) - 4 * a * c; // calcula o discriminante (delta) da equação quadrática

    if (delta < 0) // Delta negativo: não existem raízes reais
        printf("NAO EXISTE RAIZ REAL\n");
    
    else if (delta == 0) { // Delta zero: uma única raiz real (duas raízes iguais)
        double x = -b / (2.0 * a);
        printf("%.3lf\n", x);
    }
    
    else { // Delta positivo: duas raízes reais distintas
        double sqrt_delta = sqrt(delta);
        double x1 = (-b + sqrt_delta) / (2.0 * a);
        double x2 = (-b - sqrt_delta) / (2.0 * a);

        // Usa fmin e fmax para garantir a ordem crescente sem desvios condicionais (if/else)
        printf("%.3lf %.3lf\n", fmin(x1, x2), fmax(x1, x2));
    }

    return 0;
}