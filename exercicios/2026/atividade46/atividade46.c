#include <stdio.h>
#include <string.h>

void inverter_palavra(char *inicio, char *fim) {
    while (inicio < fim) {
        char temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}

int main() {
    char mensagem[210]; // array de caracteres para a mensagem
    fgets(mensagem, sizeof(mensagem), stdin); // lê a mensagem do usuário

    int tamanho = strlen(mensagem); // obtém o tamanho da mensagem
    if (tamanho > 0 && mensagem[tamanho - 1] == '\n') mensagem[tamanho - 1] = '\0'; // remove o caractere de nova linha, se presente

    char *inicio = mensagem; // ponteiro para o início da mensagem

    for (char *p = mensagem; ; p++) { // loop para percorrer a mensagem
        if (*p == ' ' || *p == '\0') { // se encontrar um espaço ou o final da mensagem
            if (p > inicio) inverter_palavra(inicio, p - 1);
            if (*p == '\0') break; // se encontrar o final da mensagem, sai do loop
            inicio = p + 1; // atualiza o ponteiro para o início da próxima palavra
        }
    }

    printf("%s\n", mensagem);
    return 0;
}