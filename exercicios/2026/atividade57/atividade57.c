#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    int n, k, valor; // n: tamanho da matriz, k: número mínimo de sorrisos por linha/coluna, valor: elemento da matriz

    if (scanf("%d %d", &n, &k) != 2) return 0;

    // vetores para guardar a quantidade de sorrisos em cada linha e coluna, inicializados com 0
    int *sorrisos_linha = (int *)calloc(n, sizeof(int));
    int *sorrisos_coluna = (int *)calloc(n, sizeof(int));

    // lê a matriz elemento por elemento
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &valor);
            
            if (valor == 1) {
                sorrisos_linha[i]++;
                sorrisos_coluna[j]++;
            }
        }
    }

    // verifica se todas as linhas e colunas cumprem o requisito mínimo k
    bool porta_abre = true;
    for (int i = 0; i < n; i++) {
        if (sorrisos_linha[i] < k || sorrisos_coluna[i] < k) { // se alguma linha ou coluna tiver menos de k sorrisos, a porta não abre
            porta_abre = false;
            break;
        }
    }

    if (porta_abre) printf("Sim\n");
    else printf("Nao\n");

    // libera a memória alocada
    free(sorrisos_linha);
    free(sorrisos_coluna);

    return 0;
}