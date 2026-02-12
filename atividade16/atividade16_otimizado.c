#include <stdio.h>
#include <stdlib.h>

// Lê o próximo "token" (sem espaços) da entrada e guarda até n chars.
// Se o token for maior que n, descarta o restante para manter a entrada alinhada.
static char *read_token_n(int n) {
    int c;

    do {
        c = getchar();

        if (c == EOF) 
            return NULL;

    } while (c == ' ' || c == '\n' || c == '\t' || c == '\r');

    char *s = (char *)malloc((size_t)n + 1); // aloca espaço para n chars + o caractere nulo
    if (!s) 
        return NULL;

    int i = 0;
    while (c != EOF && c != ' ' && c != '\n' && c != '\t' && c != '\r') { // lê até o próximo espaço ou fim de linha
        if (i < n) 
            s[i++] = (char)c;

        c = getchar();
    }

    s[i] = '\0';
    return s;
}

int main() {
    int n; // tamanho da string (pode ser ímpar; nesse caso 1 letra pode ficar no centro do palíndromo)
    if (scanf("%d", &n) != 1)
        return 0;

    char *s = read_token_n(n);
    if (!s)
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
    free(s);
    return 0;
}