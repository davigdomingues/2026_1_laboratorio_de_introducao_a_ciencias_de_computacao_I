#include <stdio.h>

int main() {
    int maxVendas = -1; // variável para armazenar o número máximo de vendas encontrado até agora
    int diasMax[31]; // array para armazenar os dias que tiveram o número máximo de vendas
    int vendasMelhor = 0; // variável para contar quantos dias tiveram o número máximo de vendas

    for (int i = 1; i <= 31; i++) { // loop para ler o número de vendas de cada dia do mês de maio
        int vendas; // variável para armazenar o número de vendas do dia atual

        if (scanf("%d", &vendas) != 1) 
            return 1;

        if (vendas > maxVendas) { // se o número de vendas do dia atual for maior que o número máximo de vendas encontrado até agora
            maxVendas = vendas; // atualiza maxVendas para o número de vendas do dia atual
            vendasMelhor = 0; // reseta vendasMelhor para contar os dias que tiveram o novo número máximo de vendas
            diasMax[vendasMelhor++] = i; // armazena o número do dia atual no array diasMax e incrementa vendasMelhor para contar quantos dias tiveram o número máximo de vendas
        } 
        
        else if (vendas == maxVendas) // se o número de vendas do dia atual for igual ao número máximo de vendas encontrado até agora
            diasMax[vendasMelhor++] = i;
    }

    printf("%d\n", maxVendas);
    for (int j = 0; j < vendasMelhor; j++) // loop para imprimir os dias que tiveram o número máximo de vendas
        printf("%d\n", diasMax[j]);

    return 0;
}