#include <stdio.h>

/*
    Versão alternativa (mais robusta):
      - Evita ponto flutuante (sem pow)
      - Usa __int128 para reduzir risco de overflow no acumulado
      - Offset cresce como 1, 2, 4, 8, ... (offset *= 2)

    Entrada: dois inteiros (a b)
    Saída: distância total percorrida (inteiro, pode exceder 64 bits)
*/

static __int128 iabs128(__int128 x) {
    return (x < 0) ? -x : x;
}

static void print_u128(__int128 x) { // imprime inteiro não-negativo em base 10 (x >= 0).
    char buf[64];
    int n = 0;

    if (x == 0) {
        putchar('0');
        return;
    }

    while (x > 0) { 
        buf[n++] = (char)('0' + (int)(x % 10)); // Converte dígito (0..9) em caractere ('0'..'9') somando o código de '0'.
        x /= 10;
    }
    while (n--) {
        putchar(buf[n]);
    }
}

int main(void) {
    long long a_in, b_in;
    if (scanf("%lld %lld", &a_in, &b_in) != 2) {
        return 1;
    }

    __int128 a = a_in, b = b_in;
    __int128 cur = a;
    __int128 total = 0;

    /*
        Alvos: a + 1, a - 2, a + 4, a - 8, ...
        step par   => +offset
        step ímpar => -offset
    */
    __int128 offset = 1;
    for (int step = 0;; step++, offset *= 2) {
        __int128 target = a + ((step % 2 == 0) ? offset : -offset);

        __int128 lo = (cur < target) ? cur : target;
        __int128 hi = (cur > target) ? cur : target;

        // Se b está no trajeto [cur, target], para exatamente em b.
        if (lo <= b && b <= hi) {
            total += iabs128(b - cur);
            break;
        }

        total += iabs128(target - cur);
        cur = target;
    }

    print_u128(total);
    putchar('\n');
    return 0;
}