#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função que calcula a quantidade de números defeituosos, perfeitos e abundantes no intervalo
void contagem(int a, int b, int *contDef, int *contPerf, int *contAbu) {
    // Inicializa explicitamente os valores apontados para garantir que a contagem comece do zero
    if (contDef != NULL) *contDef = 0;
    if (contPerf != NULL) *contPerf = 0;
    if (contAbu != NULL) *contAbu = 0;

    // Percorre o intervalo [a,b]]
    for (int i = a; i <= b; i++) {
        int soma_divisores = 0;

        // Calcula a soma dos divisores de 'i', excluindo o próprio número
        for (int j = 1; j < i; j++) {
            if (i % j == 0) soma_divisores += j;
        }

        // Classifica o número com base na soma de seus divisores
        if (soma_divisores < i) { // Defeituoso
            if (contDef != NULL) (*contDef)++;
        } 
        
        else if (soma_divisores == i) { // Perfeito
            if (contPerf != NULL) (*contPerf)++;
        } 
        
        else { // Abundante
            if (contAbu != NULL) (*contAbu)++;
        }
    }
}