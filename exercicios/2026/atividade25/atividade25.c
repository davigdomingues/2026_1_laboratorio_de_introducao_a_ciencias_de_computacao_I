#include <stdio.h>

int main() {
    int n, valor, topo = 0;
    int pilha[100000]; // guarda os números para o caso de um "0" aparecer
    long soma = 0; // soma acumulada dos números válidos (sem os "0"s), long para evitar overflow

    scanf("%d", &n);

    // leitura dos valores até o final do arquivo (EOF)
    while (scanf("%d", &valor) == 1) { // loop para encontrar os n números válidos
        if (valor == 0) { // zero detectado
            if (topo > 0) {
                topo--; 
                soma -= pilha[topo]; // subtração efetiva da soma de acúmulo de preço
            }
        }

        else { // número válido
            pilha[topo++] = valor;
            soma += valor; // acúmulo na soma auxiliar
        }
    }

    printf("%ld\n", soma);
    return 0;
}