#include <stdio.h>

int main() {
    float operando1, operando2, resultado;
    char operador;

    // lê a expressão no formato: numero operador numero
    // o espaço antes de %c ajuda a ignorar espaços em branco residuais se houver
    if (scanf("%f %c %f", &operando1, &operador, &operando2) == 3) {
        switch (operador) {
            case '+':
                resultado = operando1 + operando2;
                break;

            case '-':
                resultado = operando1 - operando2;
                break;

            case '*':
                resultado = operando1 * operando2;
                break;

            case '/':
                if (operando2 != 0)
                    resultado = operando1 / operando2;
                    
                else
                    // divisão por zero
                    return 1;

                break;
                
            default: // operador inválido
                return 1; 
        }

        printf("%.2f\n", resultado); // formatação com 2 casas decimais
    }

    return 0;
}