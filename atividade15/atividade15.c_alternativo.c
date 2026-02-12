#include <stdio.h>

int main() {
    int n; // variável para armazenar o número do fatorial máximo a ser calculado
    double soma = 1.0, termo = 1.0; // "termo" substitui o 'fatorial'. Aquele guarda o valor da divisão atual (ex: 0.5, 0.166...)

    if (scanf("%d", &n) != 1 || n < 0) 
        return 1;

    for (int i = 2; i <= n; i++) { // O loop começa em 2, porque o termo 1 já foi iniciado em 'soma' (vai até i <= n para incluir o enésimo termo)
        /* Em vez de calcular o fatorial (multiplicar), divide-se o termo anterior pelo i atual
          Exemplo: se termo era 1/2 (0.5) e i é 3:
          0.5 / 3 = 0.1666... (que é exatamente 1/6 ou 1/3!)
        */
        termo /= i;

        if (i % 2 == 0)
            soma += termo; // Pares somam (1/2!, 1/4!...)
        
        else
            soma -= termo; // Ímpares subtraem (1/3!, 1/5!...)
    }

    printf("%.10lf\n", soma);

    return 0;
}