#include <stdio.h>

int main() {
    int totalOscarVotantes = 0, totalBale = 0, totalOpera = 0, totalAmbos = 0;
    
    scanf("%d %d %d %d", &totalOscarVotantes, &totalBale, &totalOpera, &totalAmbos);

    /* Cálculo baseado em Teoria dos Conjuntos:
       n(A ∪ B) = n(A) + n(B) - n(A ∩ B) -> Total que votou em pelo menos um
       Resto = Universo - n(A ∪ B) -> Total que não votou em nenhum
    */
    printf("%d", totalOscarVotantes - (totalOpera + totalBale - totalAmbos));

    return 0;
}