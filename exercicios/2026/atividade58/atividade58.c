#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_MAX 1001 // Valor máximo para o tamanho das strings (1000 + 1 para o terminador nulo)

// Retorna negativo se s < t, positivo se s > t, e 0 se forem iguais
int comparar_lexicograficamente(const char *s, const char *t) {
    int i = 0;
    
    while (s[i] != '\0' && t[i] != '\0') {
        if (s[i] < t[i]) return -1;
        if (s[i] > t[i]) return 1;
        i++;
    }
    
    // Se uma string for prefixo da outra, a menor é a que terminou primeiro
    if (s[i] == '\0' && t[i] != '\0') return -1;
    if (s[i] != '\0' && t[i] == '\0') return 1;
    
    return 0;
}

int main() {
    char s[TAM_MAX], t[TAM_MAX];

    if (fgets(s, TAM_MAX, stdin) == NULL || fgets(t, TAM_MAX, stdin) == NULL) return 0;

    if (comparar_lexicograficamente(s, t) < 0) printf("%s", s);
    else printf("%s", t);

    return 0;
}