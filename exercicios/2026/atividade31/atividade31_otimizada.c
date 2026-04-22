#include <stdio.h>

// função para converter uma string de ternário para decimal
static long long ternario_para_decimal(const char *s) {
    long long valor = 0;

    for (int i = 0; s[i] != '\0'; i++)
        valor = valor * 3 + (s[i] - '0');

    return valor;
}

// função para converter um valor decimal para uma string de ternário
static void decimal_para_ternario(long long valor, char saida[]) {
    if (valor == 0) {
        saida[0] = '0';
        saida[1] = '\0';
        return;
    }

    char inverso[64];
    int tamanho = 0;

    while (valor > 0) { // converte o valor decimal para ternário, armazenando os dígitos em ordem inversa
        inverso[tamanho++] = (char)('0' + (valor % 3));
        valor /= 3;
    }

    for (int i = 0; i < tamanho; i++)
        saida[i] = inverso[tamanho - 1 - i];

    saida[tamanho] = '\0';
}

int main() {
    char primeira_palavra[64], resposta[64];

    if (scanf("%63s", primeira_palavra) != 1) return 0;

    int quantidade = (int)ternario_para_decimal(primeira_palavra);
    long long soma = 0;

    // lê as próximas palavras, converte de ternário para decimal e acumula a soma
    for (int i = 0; i < quantidade; i++) {
        char palavra[64];
        if (scanf("%63s", palavra) != 1) break;
        soma += ternario_para_decimal(palavra);
    }

    decimal_para_ternario(soma, resposta); // converte a soma de decimal para ternário
    printf("%s\n", resposta);

    return 0;
}