#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    char a[128], *b = a, **c = &b;

    if (fgets(a, sizeof a, stdin) == NULL)
        return 0;

    // remove o caractere de nova linha, se presente
    size_t n = strlen(a);
    if (n > 0 && a[n - 1] == '\n')
        a[n - 1] = '\0';

    // converte as vogais para maiúsculas
    for (b = a; *b != '\0'; b++) {
        if (strchr("aeiou", tolower((unsigned char)*b)))
            *b = (char)toupper((unsigned char)*b);
    }

    b = a; // reseta o ponteiro b para o início da string a
    printf("%s\n", a);

    // converte as consoantes para minúsculas
    for (b = *c; *b != '\0'; b++) {
        if (isalpha((unsigned char)*b) &&
            strchr("aeiou", tolower((unsigned char)*b)) == NULL)
            *b = (char)tolower((unsigned char)*b);
    }

    printf("%s\n", a);

    return 0;
}