#include <stdio.h>

int main() {
    int n; // tamanho da string (pode ser ímpar; nesse caso 1 letra pode ficar no centro do palíndromo)
    if (scanf("%d", &n) != 1) 
        return 0;

    char s[100000 + 5]; // string de entrada, com espaço para o caractere nulo
    if (scanf("%100000s", s) != 1)
        return 0;

    int freq[26] = {0}; // frequência de cada letra do alfabeto
    for (int i = 0; i < n && s[i] != '\0'; i++) // conta a frequência de cada letra
        freq[s[i] - 'a']++;

    int odd = 0; // contador de letras com frequência ímpar
    for (int i = 0; i < 26; i++) { // verifica quantas letras têm frequência ímpar
        if (freq[i] % 2 != 0) 
            odd++;
    }

    puts(odd <= 1 ? "Sim" : "Nao"); // se houver no máximo uma letra com frequência ímpar, é possível formar um palíndromo
    return 0;
}