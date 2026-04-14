#include <stdio.h>
#include <stdlib.h>

int main() {
    char peca;
    int Xorigem, Xdestino, Yorigem, Ydestino;
    scanf("%c %d %d %d %d", &peca, &Xorigem, &Yorigem, &Xdestino, &Ydestino);

    if ((Xorigem == Xdestino) && (Yorigem == Ydestino)) {
        printf("Movimento invalido");
        return 0;
    }
    
    switch (peca) {
        case 'T':
            if ((Xorigem == Xdestino) || (Yorigem == Ydestino)) printf("Movimento valido");
            else printf("Movimento invalido");
            break;
            
        case 'B':
            if (abs(Xdestino - Xorigem) == abs(Ydestino - Yorigem)) printf("Movimento valido");
            else printf("Movimento invalido");
            break;

        default:
            break;
    }

    return 0;
}
