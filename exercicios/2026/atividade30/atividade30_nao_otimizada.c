#include <stdio.h>

int main(void) {
    int quantidade_operacoes;
    long long x;

    if (scanf("%d %lld", &quantidade_operacoes, &x) != 2) return 0;

    long long *ponteiroB = &x, *ponteiroC = &x;

    for (int i = 0; i < quantidade_operacoes; i++) {
        char dispositivo, operador;
        long long valor;

        if (scanf(" %c %c %lld", &dispositivo, &operador, &valor) != 3) break;

        if (dispositivo == 'B') {
            if (operador == '+') *ponteiroB = *ponteiroB + valor;
            else if (operador == '-') *ponteiroB = *ponteiroB - valor;
            else if (operador == '*') *ponteiroB = *ponteiroB * valor;
            else if (operador == '/') {
                if (valor != 0) *ponteiroB = *ponteiroB / valor;
            }
        }
        
        else if (dispositivo == 'C') {
            if (operador == '+') *ponteiroC = *ponteiroC + valor;
            else if (operador == '-') *ponteiroC = *ponteiroC - valor;
            else if (operador == '*') *ponteiroC = *ponteiroC * valor;
            else if (operador == '/') {
                if (valor != 0) {
                    *ponteiroC = *ponteiroC / valor;
                }
            }
        }
    }

    printf("%lld\n", x);

    return 0;
}