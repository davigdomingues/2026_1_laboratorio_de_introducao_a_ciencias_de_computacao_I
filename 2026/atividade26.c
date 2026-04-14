#include <stdio.h>

int main() {
    int totalPrincipes = 0, poderMultiplicador = 0, totalGuardas = 0, forcaGuarda = 0, maiorSomaEncontrada = -1, maiorGuardaDoVencedor = -1, principeVencedor = 1, somaBase, maiorGuardaAtual;
    if (scanf("%d", &totalPrincipes) != 1) return 0;

    int somasTotais[totalPrincipes], maioresGuardaS[totalPrincipes];

    for (int i = 0; i < totalPrincipes; i++) {
        somaBase = 0;
        maiorGuardaAtual = 0;

        scanf("%d %d", &poderMultiplicador, &totalGuardas);

        for (int j = 0; j < totalGuardas; j++) {
            scanf("%d", &forcaGuarda);
            somaBase += forcaGuarda;
            
            // Regra de desempate 1: Guarda mais forte (sem o poder do príncipe)
            if (forcaGuarda > maiorGuardaAtual) {
                maiorGuardaAtual = forcaGuarda;
            }
        }
        // Poder do príncipe amplificado pelo poder dos guardas "especiais"
        somasTotais[i] = somaBase * poderMultiplicador;
        maioresGuardaS[i] = maiorGuardaAtual;
    }

    // Loop de comparação
    for (int i = 0; i < totalPrincipes; i++) {
        // Regra Principal: maior soma de forças
        if (somasTotais[i] > maiorSomaEncontrada) {
            maiorSomaEncontrada = somasTotais[i];
            maiorGuardaDoVencedor = maioresGuardaS[i];
            principeVencedor = i + 1; // 1-indexado
        }

        // Regra de Desempate 1: mesma soma, ganha o guarda individual mais forte
        else if (somasTotais[i] == maiorSomaEncontrada) {
            if (maioresGuardaS[i] > maiorGuardaDoVencedor) {
                maiorGuardaDoVencedor = maioresGuardaS[i];
                principeVencedor = i + 1;
            }
            // Regra de Desempate 2: Eepate em tudo, ganha o menor número (mais velho)
        }
    }

    printf("O vencedor e o Principe %d\n", principeVencedor);

    return 0;
}