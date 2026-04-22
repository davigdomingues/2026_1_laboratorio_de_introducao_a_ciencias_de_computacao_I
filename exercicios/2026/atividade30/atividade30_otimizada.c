#include <stdio.h>

static void aplica_operacao(long long *ptr, char op, long long valor) {
    switch (op) {
        case '+':
            *ptr += valor;
            break;
        case '-':
            *ptr -= valor;
            break;
        case '*':
            *ptr *= valor;
            break;
        case '/':
            if (valor != 0) *ptr /= valor;
            break;
        default:
            break;
    }
}

int main(void) {
    int quantidade_operacoes;
    long long x;

    if (scanf("%d %lld", &quantidade_operacoes, &x) != 2) return 0;

    long long *ponteiroB = &x, *ponteiroC = &x, *ponteiros[2] = {ponteiroB, ponteiroC};

    for (int i = 0; i < quantidade_operacoes; i++) {
        char dispositivo, operador;
        long long valor;

        if (scanf(" %c %c %lld", &dispositivo, &operador, &valor) != 3) break;

        int indice = (dispositivo == 'C'); // 'B' -> 0, 'C' -> 1
        aplica_operacao(ponteiros[indice], operador, valor);
    }

    printf("%lld\n", x);

    return 0;
}