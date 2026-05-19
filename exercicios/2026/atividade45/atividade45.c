#include <ctype.h>
#include <stdio.h>
#include <string.h>

static int eh_vogal(unsigned char c) {
    c = (unsigned char)tolower((int)c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

static void s_para_t(char *b) {
    for (; *b != '\0'; b++) {
        if (eh_vogal((unsigned char)*b))
            *b = (char)toupper((unsigned char)*b);
    }
}

static void t_para_r(char **c) {
    char *p = *c;
    for (; *p != '\0'; p++) {
        if (isalpha((unsigned char)*p) && !eh_vogal((unsigned char)*p))
            *p = (char)tolower((unsigned char)*p);
    }
}

int main() {
    char a[128];
    char *b = a; // ponteiro para o array a
    char **c = &b; // ponteiro para o ponteiro b

    if (fgets(a, (int)sizeof(a), stdin) == NULL)
        return 0;

    size_t n = strlen(a);
    if (n > 0 && a[n - 1] == '\n')
        a[--n] = '\0';

    s_para_t(b);
    printf("%s\n", a);

    t_para_r(c);
    printf("%s\n", a);

    return 0;
}