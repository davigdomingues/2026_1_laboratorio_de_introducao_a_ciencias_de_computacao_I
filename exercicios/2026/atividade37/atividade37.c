#include <stdio.h>

int main() {
    int n;
    unsigned long long a = 0, b = 1, c; // uso de long long para evitar overflow
    scanf("%d", &n);

    if (n == 0) printf("0\n");
    
    else {
        for (int i = 2; i <= n; i++) { // loop para calcular o n-ésimo termo da sequência de Fibonacci, a partir da operação swap
            c = a + b;
            a = b;
            b = c;
        }

        printf("%llu\n", b); // imprime o n-ésimo termo da sequência de Fibonacci
    }

    return 0;
}