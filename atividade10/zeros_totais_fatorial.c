#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Conta o TOTAL de dígitos '0' na representação decimal de N!.
 *
 * Importante:
 * - Isto NÃO é “zeros à direita” (trailing zeros). Aqui contamos zeros em qualquer posição.
 * - Para N grande, N! tem dígitos demais para caber em tipos nativos; por isso usamos inteiro grande.
 *
 * Entrada:
 * - Um inteiro N (aceita negativo; usa |N|).
 *
 * Saída:
 * - Um inteiro: quantidade de dígitos '0' em N!.
 *
 * Estratégia:
 * 1) Computa N! com um "big integer" armazenado em um vetor de blocos na base 10^9.
 *    - a[0] guarda os 9 últimos dígitos.
 *    - a[1] guarda os próximos 9 dígitos, etc.
 * 2) Multiplica o big integer por i = 2..N, propagando carry.
 * 3) Conta zeros bloco a bloco:
 *    - Bloco mais significativo: conta zeros sem considerar zeros à esquerda.
 *    - Demais blocos: cada bloco representa exatamente 9 dígitos (com zeros à esquerda), então
 *      contamos 9 dígitos sempre.
 *
 * Complexidade (ordem de grandeza):
 * - Memória: O(d) blocos, onde d é o número de dígitos de N! (d ~ N log10 N).
 * - Tempo: multiplicação ingênua ~ soma do nº de blocos ao longo do loop (cresce rápido).
 *
 * Observação prática:
 * - Este método é adequado para N relativamente pequeno/médio. Para N muito grande (ex. 10^9)
 *   é impossível materializar N!; aí só dá para responder perguntas como “zeros à direita”.
 */

int main() {
    long long n;
    if (scanf("%lld", &n) != 1) {
        return 0;
    }

    if (n < 0) {
        n = -n;
    }

    /* Base 10^9: facilita multiplicação e depois contagem de dígitos (9 dígitos por bloco). */
    const uint32_t base = 1000000000u;

    size_t cap = 16;
    size_t len = 1;
    uint32_t *a = (uint32_t *)malloc(cap * sizeof(*a));
    if (!a) {
        return 0;
    }

    a[0] = 1;

    for (long long i = 2; i <= n; i++) {
        unsigned long long carry = 0;
        for (size_t j = 0; j < len; j++) {
            unsigned long long tmp = (unsigned long long)a[j] * (unsigned long long)i + carry;
            a[j] = (uint32_t)(tmp % base);
            carry = tmp / base;
        }

        while (carry > 0) {
            if (len == cap) {
                cap *= 2;
                uint32_t *next = (uint32_t *)realloc(a, cap * sizeof(*a));
                if (!next) {
                    free(a);
                    return 0;
                }
                a = next;
            }
            a[len++] = (uint32_t)(carry % base);
            carry /= base;
        }
    }

    long long zeros = 0;

    /*
     * Bloco mais significativo (o último do vetor): não devemos contar zeros à esquerda,
     * porque eles não existem na escrita decimal do número.
     */
    uint32_t msb = a[len - 1];
    if (msb == 0) {
        /* Só aconteceria se o número inteiro fosse 0 (não ocorre para N! com N>=0). */
    } else {
        while (msb > 0) {
            if (msb % 10u == 0u) {
                zeros++;
            }
            msb /= 10u;
        }
    }

    /*
     * Demais blocos: cada bloco deve ser interpretado com 9 dígitos, completando com zeros
     * à esquerda quando necessário (ex.: bloco 42 representa "000000042").
     */
    for (size_t idx = 0; idx + 1 < len; idx++) {
        uint32_t x = a[idx];
        if (x == 0) {
            zeros += 9;
            continue;
        }
        for (int k = 0; k < 9; k++) {
            if (x % 10u == 0u) {
                zeros++;
            }
            x /= 10u;
        }
    }

    printf("%lld\n", zeros);

    free(a);
    return 0;
}