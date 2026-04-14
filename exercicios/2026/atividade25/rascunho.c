#include <stdio.h>

int main() {
    int n, valor, topo = 0;
    int pilha[100000]; // guarda os números para o caso de um "0" aparecer
    long soma = 0; // soma acumulada dos números válidos (sem os "0"s), long para evitar overflow

    // Lemos a quantidade de itens VÁLIDOS que o chefe deseja
    if (scanf("%d", &n) != 1) return 0;

    // O loop continua até que o topo da pilha atinja a quantidade 'n'
    while (topo < n) { 
        if (scanf("%d", &valor) != 1) break;

        if (valor == 0) { // zero detectado (o número anterior era um erro)
            if (topo > 0) {
                topo--; 
                soma -= pilha[topo]; // subtração do valor incorreto da soma total
            }
        }

        else { // número válido (por enquanto)
            pilha[topo++] = valor;
            soma += valor; // acúmulo na soma auxiliar
        }
    }

    printf("%ld\n", soma); // imprime o custo total da lista final
    return 0;
}
