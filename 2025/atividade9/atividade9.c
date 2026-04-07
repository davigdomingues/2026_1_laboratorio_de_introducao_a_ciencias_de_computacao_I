/*
  Cenário de sucesso: lê duas posições inteiras a (Cap) e b (Alan), simula a estratégia de busca
  (a+1, a-2, a+4, a-8, ...) até o movimento cruzar b, e imprime a distância total percorrida.
  Retorna 0 quando consegue ler a entrada e produzir a resposta.
*/

#include <stdio.h>
#include <stdlib.h> // llabs -> calcula valor absoluto de long long
#include <math.h> // pow

int main(void) {
    /*
    long long não é “obrigatório” se o problema garantir resposta pequena, mas é mais seguro porque a distância total
    pode crescer rápido nessa estratégia, se for considerado um caso mais genérico.

    Adendo de variáveis:
        - a, b: posições de entrada (até 64 bits)
        - cur: posição atual (inicia em a)
        - total: distância acumulada
        - offset: distância do próximo passo (2^i)
        - sign: direção do próximo passo (+ ou -)
        - target: próximo alvo (a + sign * offset)
        - lo, hi: extremos do intervalo percorrido no passo (para verificar se b está no caminho)
    */

    long long a, b;

    if (scanf("%lld %lld", &a, &b) != 2)
        return 1;


    if (a == b) {
        printf("0\n");
        return 0;
    }

    long long cur = a, total = 0, offset = 0, sign = 0, target = 0, lo = 0, hi = 0;

    // Alvos: a+1, a-2, a+4, a-8, ... => a + (± 2^i), começando com i = 0 (direita).
    for (int i = 0;; i++) {
        offset = (long long)pow(2.0, i); // 2^i (assumindo i pequeno)
        sign = (i % 2 == 0) ? +1LL : -1LL; // +, -, +, -, ...
        target = a + sign * offset; // próximo alvo

        // intervalo percorrido no passo (independente do sentido)
        lo = (cur < target) ? cur : target; // distância menor
        hi = (cur > target) ? cur : target; // distância maior

        if (lo <= b && b <= hi) { // Se b está no caminho entre cur e target, termina no ponto b.
            total += llabs(b - cur);
            break;
        }

        // Caso contrário, completa o passo até o alvo e continua.
        total += llabs(target - cur);
        cur = target;
    }

    printf("%lld\n", total);
    return 0;
}