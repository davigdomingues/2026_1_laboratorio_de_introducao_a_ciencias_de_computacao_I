#include <stdio.h>

int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        /*
         * O código original dava Segmentation Fault porque a função f4() chamava a si mesma até 100 milhões de vezes (10^8), estourando a pilha de memória
         *
         * No caso, a função fazia o seguinte:
         * - f1(x) apenas soma 1 (x + 1)
         * - f2(x) apenas subtrai 1 (x - 1)
         * - f3(a, b) fica somando 1 no 'a' e tirando 1 do 'b' até o 'b' zerar. Na prática, é só a + b
         * 
         * Dessa forma:
         * resp = f3(f4(f2(a)), f3(a, f3(a,a)))
         * 
         * Resolvendo de dentro pra fora:
         * - f3(a, a) vira (a + a) = 2a
         * - f3(a, 2a) vira (a + 2a) = 3a
         * - f2(a) vira (a - 1)
         * 
         * Então, f4(a) é: f4(a - 1) + 3a
         * 
         * Ou seja, ela vai somando os múltiplos de 3: 3n + 3(n-1) + 3(n-2) ... até 3(1)
         * 
         * Se colocarmos o 3 em evidência, sobra a soma de 1 até n. Pela fórmula de P.A: (n*(n+1))/2
         * 
         * Multiplicando por 3, teremos um desempenho de O(1) e sem estourar memória :)
         */
        long long resposta = (3*n*(n+1))/2;
        printf("%lld\n", resposta);
    }
    
    return 0;
}