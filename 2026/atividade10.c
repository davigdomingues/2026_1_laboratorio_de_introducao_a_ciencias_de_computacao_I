#include <stdio.h>

int main() {
    float v0 = 0.0, gravidade = 0.0;
    scanf ("%f %f", &v0, &gravidade);
    
    // a altura máxima é tal que: H = (v0y)²/(2g). 
    // Nesse cenário, sen(theta) = 90°, ou seja, v0y = v0 -> lançamento oblíquo!
    printf("%.2f", v0*v0/(2*gravidade));

    return 0;
}