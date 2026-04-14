#include <stdio.h>

void swap(int *a, int *b) { // função para trocar os valores de dois inteiros usando ponteiros
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int canalA, canalB; // variáveis para armazenar os valores dos canais A e B, respectivamente

    if (scanf("%d %d", &canalA, &canalB) != 2)
        return 0;

    int *pA = &canalA; // ponteiro para o canal A
    int *pB = &canalB; // ponteiro para o canal B
    swap(pA, pB); // chamada da função swap

    printf("%d %d\n", *pA, *pB);

    return 0;
}