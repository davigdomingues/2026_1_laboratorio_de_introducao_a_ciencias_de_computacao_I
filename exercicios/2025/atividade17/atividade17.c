#include <stdio.h>

int main() {
    int dias[31]; // array para armazenar o número de dias do mês de maio
    int diaMelhor = 0; // variável para armazenar o dia com mais vendas
    int vendasMelhor; // variável para armazenar o número de vendas do dia com mais vendas

    for (int i = 0; i < 31; i++) { // loop para ler o número de dias do mês de maio
        if (scanf("%d", &dias[i]) != 1) // lê um inteiro do usuário e armazena no array dias
            return 1; // retorna um código de erro se a leitura falhar
    }

    vendasMelhor = dias[0]; // inicializa vendasMelhor com o número de vendas do primeiro dia (dia 1)
    for (int i = 0; i < 31; i++) { // loop para encontrar o dia com mais vendas
        if (dias[i] > vendasMelhor) { // se o número de vendas do dia atual for maior que o número de vendas do dia melhor encontrado até agora
            diaMelhor = i + 1; // atualiza diaMelhor para o dia atual (i + 1, pois os índices do array começam em 0)
            vendasMelhor = dias[i]; // atualiza vendasMelhor para o número de vendas do dia atual
        }
    }

    printf("%d\n%d\n", vendasMelhor, diaMelhor); // imprime o número de vendas do dia com mais vendas e o número do dia correspondente

    return 0;
}