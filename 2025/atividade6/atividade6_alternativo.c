#include <stdio.h>

/*
    NOTA DE EFICIÊNCIA:
    Este programa é considerado mais eficiente e robusto que a versão 'atividade6.c'.
    1. Usa 'double' em vez de 'float': Em arquiteturas modernas (x64), operações com double são nativas e preferíveis para evitar erros de precisão.
    2. I/O Otimizado: Realiza apenas uma chamada de sisterma (scanf) para ler todos os dados, reduzindo overhead.
    3. Função min modular: Facilita a leitura e inlining pelo compilador.
*/

double min(double a, double b) { // função para encontrar o menor entre dois números
    return (a < b) ? a : b;
}

int main() {
    double a, b, c, d; // números reais a serem informados pelo usuário
    
    if (scanf("%lf %lf %lf %lf", &a, &b, &c, &d) != 4) { // lê os quatro números reais
        return 1;
    }

    double smallest = min(a, min(b, min(c, d))); // encontra o menor valor entre os quatro
    double mean = (a + b + c + d - smallest) / 3.0; // calcula a média usando a fórmula: (a + b + c + d - MIN) / 3
    
    printf("%lf\n", mean); // imprime o resultado

    return 0;
}