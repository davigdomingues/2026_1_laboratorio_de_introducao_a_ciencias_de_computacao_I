#include <stdio.h>

int main(void) {
    int n, m; // número de alunos e número de notas
    int nota[100][100], extra[100][100]; // arrays para armazenar as notas e as notas extras

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) { // loop para ler as notas de cada aluno
        for (int j = 0; j < m; j++) scanf("%d", &nota[i][j]);
    }

    for (int i = 0; i < n; i++) { // loop para ler as notas extras de cada aluno
        for (int j = 0; j < m; j++) scanf("%d", &extra[i][j]);
    }

    for (int i = 0; i < n; i++) { // loop para calcular a nota final de cada aluno
        for (int j = 0; j < m; j++) {
            int final = nota[i][j] + extra[i][j]; // soma as notas e as notas extras
            if (final > 100) final = 100; // se a nota final for maior que 100, ela é limitada a 100
            printf("%d%c", final, (j < m - 1) ? ' ' : '\n'); // imprime a nota final, separando por espaço se não for a última nota
        }
    }

    return 0;
}