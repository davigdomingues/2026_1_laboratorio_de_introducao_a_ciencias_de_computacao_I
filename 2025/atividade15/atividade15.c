#include <stdio.h>
#include <math.h>

int main() {
    int n; // variável para armazenar o número do fatorial máximo a ser calculado
    double soma = 1.0, fatorial = 1.0; // variável para armazenar o resultado do somatório, iniciada com o primeiro termo da série (1) + variável para armazenar o valor do fatorial, iniciada com 1 (0! = 1)

    if (scanf("%d", &n) != 1 || n < 0) // lê um inteiro do usuário e verifica se a leitura foi bem-sucedida e se o número é não-negativo
        return 1; // retorna um código de erro

    for (int i = 2; i <= n; i++) { // loop para calcular o fatorial de 2 até n
        fatorial *= i; // atualiza o valor do fatorial para o próximo número (fatorial de i)
        soma += pow(-1, i)/fatorial; // atualiza o valor da soma com o próximo termo da série, que é 1/(i+1)! multiplicado por (-1)^i para alternar os sinais
    }

    printf("%lf\n", soma); // imprime o resultado do somatório 1 + 1/2! - 1/3! + 1/4! ... - 1/n!

    return 0;
}