#include <stdio.h>

int main() {
    char mensagem[50], c;
    scanf("%s", mensagem);

    // Manipulação da tabela ASCII
    for (int i = 0; mensagem[i] != '\0'; i++) {
        c = mensagem[i];
        if (c >= 'a' &&  c <= 'z') mensagem[i] = 'z' - (c - 'a'); // Inverte minúsculas
        else if (c >= 'A' && c <= 'Z') mensagem[i] = 'Z' - (c - 'A'); // Inverte maiúsculas
    }

    printf("%s\n", mensagem);

    return 0;
}