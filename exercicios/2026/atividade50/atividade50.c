#include <stdio.h>

int main(void) {
    char first[205], s[205]; // first: primeiro token, s: string de entrada
    if (scanf("%199s", first) != 1) return 0;

    int is_digits = 1;
    for (int i = 0; first[i] != '\0'; i++) { // verifica se first é composto só por dígitos
        if (first[i] < '0' || first[i] > '9') {
            is_digits = 0;
            break;
        }
    }

    if (is_digits) { // se first é só dígitos, lê a string completa para s
        if (scanf("%199s", s) != 1) return 0;
    } 
    
    else { // caso contrário, first é a string de entrada
        int i;
        for (i = 0; first[i] != '\0'; i++) s[i] = first[i]; // copia first para s
        s[i] = '\0';
    }

    int freq[26] = {0}; // frequência de cada letra maiúscula
    for (int i = 0; s[i] != '\0'; i++) { // conta frequência de letras maiúsculas
        int idx = s[i] - 'A';
        if (idx >= 0 && idx < 26) freq[idx]++; // incrementa a frequência da letra correspondente
    }

    // moda: maior frequência e, em empate, menor letra lexicograficamente.
    int best = 0;
    for (int i = 1; i < 26; i++) if (freq[i] > freq[best]) best = i; // ">" mantém a menor letra no empate

    printf("%c\n", (char)('A' + best)); // imprime a letra mais frequente
    return 0;
}