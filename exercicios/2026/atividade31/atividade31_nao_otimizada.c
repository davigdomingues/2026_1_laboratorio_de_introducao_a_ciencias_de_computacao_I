#include <stdio.h>

int main() {
    char primeira_palavra[64], resultado[64];
    int k = 0; // índice para o resultado em ternário

    if (scanf("%63s", primeira_palavra) != 1) return 0;

    // converte a primeira palavra de ternário para decimal
    int quantidade = 0;
    for (int i = 0; primeira_palavra[i] != '\0'; i++)
        quantidade = quantidade * 3 + (primeira_palavra[i] - '0'); // o '0' é para converter o caractere para dígito

    long long soma = 0;

    // lê as próximas palavras, converte de ternário para decimal e acumula a soma
    for (int i = 0; i < quantidade; i++) {
        char palavra[64];

        if (scanf("%63s", palavra) != 1) break;

        long long valor = 0; // converte a palavra de ternário para decimal
        long long potencia = 1; // potência de 3 para cada dígito
        int tamanho = 0; // calcula o tamanho da palavra

        while (palavra[tamanho] != '\0') tamanho++;

        // percorre a palavra de trás para frente para calcular o valor decimal
        for (int j = tamanho - 1; j >= 0; j--) {
            valor += (palavra[j] - '0') * potencia;
            potencia *= 3;
        }

        soma += valor;
    }

    if (soma == 0) {
        printf("0\n");
        return 0;
    }

    // converte a soma de decimal para ternário
    while (soma > 0) {
        resultado[k] = (char)('0' + (soma % 3)); // o '0' é para converter o dígito para caractere
        soma = soma / 3;
        k++;
    }

    // imprime o resultado em ternário, que está armazenado de trás para frente
    for (int i = k - 1; i >= 0; i--)
        printf("%c", resultado[i]);

    printf("\n");

    return 0;
}