#include <stdio.h>

int main() {
    int n, p, m; // n: tamanho do tabuleiro, p: posição inicial, m: número de dados lançados
    scanf("%d %d %d", &n, &p, &m);

    int tabuleiro[n]; // array de inteiros para o tabuleiro
    for (int i = 0; i < n; i++) scanf("%d", &tabuleiro[i]);

    int dados[m]; // array de inteiros para os dados
    for (int i = 0; i < m; i++) scanf("%d", &dados[i]);

    int *atual = tabuleiro + p; // ponteiro para a posição atual
    int *limite = tabuleiro + n; // ponteiro para o final do tabuleiro
    long long saldo = 0; // saldo acumulado

    for (int i = 0; i < m; i++) {
        atual += dados[i]; // incrementa a posição atual pelo valor do dado
        if (atual >= limite) atual = tabuleiro + (atual - tabuleiro) % n;
        saldo += *atual; // adiciona o valor da posição atual ao saldo
    }

    printf("%lld", saldo);
    return 0;
}