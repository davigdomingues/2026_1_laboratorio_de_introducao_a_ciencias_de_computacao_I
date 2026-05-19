#include <stdio.h>

int main() {
    int n, k; // n: número de salas, k: número de salas seguidas
    scanf("%d %d", &n, &k);

    int seguidas = 0, sala, nro_salas = 0, trapacas = 0;

    for (int i = 0; i < n; i++) 
        if (scanf("%d", &sala) == 1) { // loop para ler os valores das salas
            if (sala == 0) seguidas = 0; // se a sala for 0, reseta o numero de salas seguidas
            else if (seguidas == k) nro_salas++; // se o numero de salas seguidas for igual a k, incrementa o numero de salas
            else seguidas++; // se a sala for 1, incrementa o numero de salas seguidas
        }

    printf("%d", nro_salas);
    return 0;
}