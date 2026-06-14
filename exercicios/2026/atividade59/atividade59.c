#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_ALFABETO 26

int main() {
    int n; // Total de caracteres a serem lidos
    if (scanf("%d", &n) != 1) return 0;

    // Retira a quebra de linha
    getchar();

    int contagem[TAM_ALFABETO] = {0};

    // Lê caractere por caractere e conta a frequência de cada letra
    for (int i = 0; i < n; i++) {
        char c = getchar();
        if (c >= 'a' && c <= 'z') contagem[c - 'a']++;
    }

    // Conta quantas letras aparecem um número ímpar de vezes
    int impares = 0;
    for (int i = 0; i < TAM_ALFABETO; i++) if (contagem[i] % 2 != 0) impares++;

    // Se houver mais de 1 letra com contagem ímpar, não pode ser palíndromo
    if (impares > 1) printf("NAO\n");
    else printf("SIM\n");

    return 0;
}