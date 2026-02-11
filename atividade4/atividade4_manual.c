#include <stdio.h>
#include <string.h>

int main() {
    char binario[5]; // variável para armazenar a string binária (até 4 bits + '\0')
    int decimal = 0; // variável para armazenar o resultado decimal
    char extra;
    
    scanf("%4s", binario); // lê a string binária (máximo 4 caracteres)
    
    // verifica se há caracteres extras (entrada maior que 4 bits)
    if (scanf("%c", &extra) == 1 && extra != '\n' && extra != ' ') {
        printf("Erro: entrada deve ter no máximo 4 bits\n");
        return 1;
    }
    int len = strlen(binario);

    // percorre cada caractere da string binária
    for (int i = 0; i < len; i++)
        // multiplica o resultado atual por 2 e adiciona o bit atual
        decimal = decimal * 2 + (binario[i] - '0');
    
    printf("%d\n", decimal); // imprime o número decimal
    
    return 0;
}