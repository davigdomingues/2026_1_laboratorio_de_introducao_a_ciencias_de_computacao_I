#include <stdio.h>
#include <stdlib.h>

static void swapSemTempXor(int *a, int *b) { // função para trocar os valores de dois inteiros, usando ponteiros e sem variável temporária, utilizando a operação XOR
    /* 
      por que funciona:
      seja A = *a e B = *b.
      1) *a = A ^ B
      2) *b = B ^ (A ^ B) = A        (pois B^B = 0 e 0^A = A)
      3) *a = (A ^ B) ^ A = B        (pois A^A = 0)

      observação: se a == b (mesmo endereço), vira *a ^= *a => 0; por isso o guard.
    */

    if (!a || !b || a == b)
        return;

    *a ^= *b; // a recebe a XOR b
    *b ^= *a; // b recebe b XOR (a XOR b) = a
    *a ^= *b; // a recebe (a XOR b) XOR a = b
}

int main() {
    int *pa = malloc(sizeof(int)), *pb = malloc(sizeof(int)); // aloca memória para dois inteiros e atribui os endereços para pa e pb

    if (!pa || !pb) { // verifica se a alocação de memória foi bem-sucedida
        free(pa); // libera a memória alocada para pa, mesmo que seja NULL
        free(pb); // libera a memória alocada para pb, mesmo que seja NULL

        return 1;
    }

    if (scanf("%d %d", pa, pb) != 2) { // lê dois inteiros do usuário e armazena nos endereços apontados por pa e pb
        free(pa);
        free(pb);

        return 1;
    }

    
    printf("%d %d\n", *pa, *pb); // antes da troca
    swapSemTempXor(pa, pb); // chamada de função para trocar os valores
    printf("%d %d\n", *pa, *pb); // depois da troca

    free(pa);
    free(pb);

    return 0;
}