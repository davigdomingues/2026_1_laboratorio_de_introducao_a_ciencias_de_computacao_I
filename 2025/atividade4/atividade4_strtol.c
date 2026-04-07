#include <stdio.h>
#include <stdlib.h>

int main() {
    char binario[5]; // variável para armazenar a string binária (até 4 bits + '\0')
    char extra;
    
    scanf("%4s", binario); // lê a string binária (máximo 4 caracteres)
    
    // verifica se há caracteres extras (entrada maior que 4 bits)
    if (scanf("%c", &extra) == 1 && extra != '\n' && extra != ' ') {
        printf("Erro: entrada deve ter no máximo 4 bits\n");
        return 1;
    }
    
    // converte a string binária para decimal usando strtol com base 2
    long decimal = strtol(binario, NULL, 2);
    
    printf("%ld\n", decimal); // imprime o número decimal
    
    return 0;
}