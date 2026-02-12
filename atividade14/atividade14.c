#include <stdio.h>
#include <stdlib.h>

void swapSemTemp(int *a, int *b) { // função para trocar os valores de dois inteiros, usando ponteiros e sem variável temporária
    *a = *a + *b; // soma os valores apontados por a e b e armazena o resultado no endereço apontado por a
    *b = *a - *b; // subtrai o valor apontado por b do valor atualizado de a e armazena o resultado no endereço apontado por b (que agora contém o valor original de a)
    *a = *a - *b; // subtrai o valor atualizado de b (que agora contém o valor original de a) do valor atualizado de a e armazena o resultado no endereço apontado por a (que agora contém o valor original de b)
}

int main() {
    int *pa = malloc(sizeof(int)), *pb = malloc(sizeof(int)); // aloca memória para dois inteiros e atribui os endereços para pa e pb

    if (pa == NULL || pb == NULL) { // verifica se a alocação de memória foi bem-sucedida
        fprintf(stderr, "Erro ao alocar memória\n");

        return 1; // retorna um código de erro
    }

    if (scanf("%d %d", pa, pb) != 2) { // lê dois inteiros do usuário e armazena nos endereços apontados por pa e pb
        fprintf(stderr, "Erro ao ler os números\n");

        free(pa); // libera a memória alocada para pa
        free(pb); // libera a memória alocada para pb

        return 1; // retorna um código de erro
    }

    printf("%d %d\n", *pa, *pb); // imprime os valores armazenados nos endereços apontados por pa e pb (antes da troca)
    swapSemTemp(pa, pb); // chama a função para trocar os valores apontados por pa e pb sem usar uma variável temporária
    printf("%d %d\n", *pa, *pb); // imprime os valores armazenados nos endereços apontados por pa e pb (após a troca)

    free(pa);
    free(pb);

    return 0;
}