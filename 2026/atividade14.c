#include <stdio.h>
#include <math.h>

int main() {
    float xp = 0.0, yp = 0.0, zp = 0.0, xc = 0.0, yc = 0.0, zc = 0.0, raio = 0.0, distanciaExtra = 0.0;
    
    scanf("%f %f %f", &xp, &yp, &zp);
    scanf("%f %f %f", &xc, &yc, &zc);
    scanf("%f", &raio);

    distanciaExtra = sqrt(pow(xp-xc,2) + pow(yp-yc,2) + pow(zp-zc,2));
    
    if (raio == distanciaExtra) printf("pertence");
    else if (raio > distanciaExtra) printf("interna");
    else printf("externa");
    
    return 0;
}