#include <stdio.h>

long long ternario_para_decimal(const char *s) { // função para converter uma string de ternário para decimal
    long long valor = 0; // variável para armazenar o valor decimal
    for (int i = 0; s[i] != '\0'; i++) valor = valor * 3 + (s[i] - '0'); // converte a string de ternário para decimal

    return valor;
}

int main() {
    char s0[64], palavra[64];
    if (scanf("%63s", s0) != 1) return 0;

    int n = ternario_para_decimal(s0);
    long long sinal[n]; // array para armazenar os valores dos sinais

    for (int i = 0; i < n; i++) {
        scanf("%63s", palavra);
        sinal[i] = ternario_para_decimal(palavra); // converte a palavra de ternário para decimal e armazena no array sinal
    }

    int m;
    scanf("%d", &m);

    long long padrao[m]; // array para armazenar os valores dos padrões
    for (int i = 0; i < m; i++) scanf("%lld", &padrao[i]); // lê os valores dos padrões e armazena no array padrão

    int ocorrencias = 0, coincide;
    for (int i = 0; i <= n - m; i++) { // percorre o array sinal
        coincide = 1; // inicializa a variável coincide como 1 (true)
        for (int j = 0; j < m; j++) { // percorre o array padrão
            if (sinal[i + j] != padrao[j]) {
                coincide = 0; // se algum valor do sinal for diferente do padrão, o sinal não coincide
                break;
            }
        }

        if (coincide) ocorrencias++; // se o sinal coincide, incrementa o contador de ocorrências
    }

    printf("%d\n", ocorrencias);
    return 0;
}