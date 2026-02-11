#include <stdio.h>

int main() {
    char nome[10]; // variável para armazenar o nome do usuário

    scanf("%9s", nome); // lê o nome do usuário, limitando a entrada a 9 caracteres para evitar estouro de buffer
    printf("Bom dia, %s!\n", nome); // imprime a mensagem de saudação com o nome do usuário

    return 0;
}