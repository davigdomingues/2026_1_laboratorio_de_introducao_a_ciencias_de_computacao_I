#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, z1, x2, y2, z2;
    scanf("%lf %lf %lf", &x1, &y1, &z1);
    scanf("%lf %lf %lf", &x2, &y2, &z2);
    
    if (((x1*y2) == (x2*y1)) && ((x1*z2) == (x2*z1)) && ((y1*z2) == (y2*z1))) {
        printf("LD");
        return 0;
    }
    
    else printf("LI");

    return 0;
}