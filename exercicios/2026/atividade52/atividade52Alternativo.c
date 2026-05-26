#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função responsável pelo cálculo do determinante de ordem 2
double calcular_determinante_2x2(double a11, double a12, double a21, double a22) {
    return (a11 * a22) - (a12 * a21);
}

// Função para extrair a submatriz e calcular o cofator de um elemento (i, j)
double obter_cofator(double matriz[3][3], int linha, int coluna) {
    double submatriz[2][2];
    int sub_i = 0;

    for (int i = 0; i < 3; i++) {
        if (i == linha) continue;
        int sub_j = 0;

        for (int j = 0; j < 3; j++) { // Itera sobre as colunas para preencher a submatriz, pulando a coluna do elemento
            if (j == coluna) continue;
            submatriz[sub_i][sub_j] = matriz[i][j];
            sub_j++;
        }

        sub_i++;
    }

    double det2x2 = calcular_determinante_2x2(submatriz[0][0], submatriz[0][1], submatriz[1][0], submatriz[1][1]);
    // Aplica o sinal com base em (-1)^(i+j): como os índices começam em 0, a paridade da soma se mantém idêntica à de índices iniciando em 1
    if ((linha + coluna) % 2 != 0) return -det2x2;

    return det2x2;
}

// Função para calcular o determinante 3x3 via Expansão de Laplace usando a primeira linha
double calcular_determinante_3x3(double matriz[3][3]) {
    return (matriz[0][0] * obter_cofator(matriz, 0, 0)) + (matriz[0][1] * obter_cofator(matriz, 0, 1)) + (matriz[0][2] * obter_cofator(matriz, 0, 2));
}

int main() {
    double v_E[3];
    // Leitura dos coeficientes do vetor na base E (alpha, beta, gamma)
    if (scanf("%lf %lf %lf", &v_E[0], &v_E[1], &v_E[2]) != 3) return 1;

    double M_EF[3][3];
    // Leitura da matriz de mudança de base M_EF
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (scanf("%lf", &M_EF[i][j]) != 1) return 1;
        }
    }

    // Passos 1 e 2: Calcular a matriz de cofatores e transpor para obter a Adjunta
    double adj[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            // A matriz adjunta é a transposta da matriz de cofatores
            adj[j][i] = obter_cofator(M_EF, i, j);
    }

    // Passo 3: Calcular o determinante de M_EF
    double det = calcular_determinante_3x3(M_EF);
    if (det == 0.0) return 1; // Evita divisão por zero, caso a matriz não seja inversível

    // Passo 4: Calcular a matriz inversa (M_FE) utilizando a adjunta e o determinante
    double M_FE[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            M_FE[i][j] = adj[i][j] / det;
    }

    // Passo 5: Multiplicar o vetor na base E pela matriz inversa M_FE para obter a base F
    double v_F[3] = {0.0, 0.0, 0.0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            v_F[i] += M_FE[i][j] * v_E[j];
    }

    // Saída formatada com 3 casas decimais e quebra de linha obrigatória no final
    printf("%.3lf %.3lf %.3lf\n", v_F[0], v_F[1], v_F[2]);

    return 0;
}