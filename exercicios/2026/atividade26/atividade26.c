#include <stdio.h>

int main() {
    int totalPacientes, nroPares = 0, nroImpares = 0, paciente;
    scanf("%d", &totalPacientes);

    for (int i = 0; i < totalPacientes; i++) {
        if (scanf("%d", &paciente) != 1) return 0;

        if (paciente == 0) continue;
        else if (paciente % 2 == 0) nroPares++;
        else nroImpares++;
    }

    if (nroPares > nroImpares) printf("Pares\n");
    else printf("Impares\n");

    return 0;
}