#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { // estrutura para armazenar a posição e a distância
    int r, c, dist; // r: linha, c: coluna, dist: distância
} No;

static int dentro(int n, int *m, int r, int c) { // função para verificar se a posição está dentro do mapa
    return r >= 0 && r < n && c >= 0 && c < m[r];
} // retorna 1 se a posição está dentro do mapa, 0 caso contrário

static void deslizar(char **map, int n, int *m, int r, int c, int dr, int dc, int *tr, int *tc) { // função para deslizar o bloco
    *tr = r; // atualiza a linha
    *tc = c; // atualiza a coluna
    int nr = r + dr, nc = c + dc; // calcula a nova posição

    while (dentro(n, m, nr, nc) && map[nr][nc] != '#') { // enquanto a posição está dentro do mapa e o bloco não é um obstáculo
        *tr = nr; // atualiza a linha
        *tc = nc; // atualiza a coluna
        nr += dr; // incrementa a linha
        nc += dc; // incrementa a coluna
    }
}

static void mapa_free(char **map, int *cols, int n, int **vis) { // função para liberar a memória do mapa
    for (int i = 0; i < n; i++) { // loop para liberar a memória de cada linha do mapa
        free(map[i]);
        free(vis[i]);
    }

    free(map);
    free(vis);
    free(cols);
}

int main(void) {
    int n; // variável para armazenar o número de linhas do mapa
    scanf("%d", &n);

    int *m = malloc((size_t)n * sizeof(int)); // aloca memória para o número de colunas de cada linha
    char **map = malloc((size_t)n * sizeof(char *)); // aloca memória para o mapa
    int **vis = malloc((size_t)n * sizeof(int *)); // aloca memória para a matriz de visitados

    if (m == NULL || map == NULL || vis == NULL) return 1;

    int ar = -1, ac = -1, br = -1, bc = -1; // variáveis para armazenar a posição inicial e final do bloco

    for (int i = 0; i < n; i++) { // loop para ler o mapa
        scanf("%d", &m[i]);

        map[i] = malloc((size_t)m[i] + 1); // aloca memória para a linha i do mapa
        vis[i] = calloc((size_t)m[i], sizeof(int)); // aloca memória para a linha i da matriz de visitados

        if (map[i] == NULL || vis[i] == NULL) return 1; // se a alocação falhar, retorna 1

        for (int j = 0; j < m[i]; j++) { // loop para ler a linha i do mapa
            scanf(" %c", &map[i][j]);

            map[i][j + 1] = '\0';

            if (map[i][j] == 'A') { // se o bloco é o bloco inicial, atualiza a posição inicial
                ar = i;
                ac = j;
            } 
            
            else if (map[i][j] == 'B') { // se o bloco é o bloco final, atualiza a posição final
                br = i;
                bc = j;
            }
        }
    }

    static const int dr[] = {-1, 1, 0, 0}; // vetor para as direções possíveis
    static const int dc[] = {0, 0, -1, 1}; // vetor para as direções possíveis

    No *fila = malloc((size_t)n * 102 * sizeof(No)); // aloca memória para a fila, 102 é o número máximo de posições possíveis
    if (fila == NULL) return 1; // se a alocação falhar, retorna 1

    int ini = 0, fim = 0; // variáveis para armazenar o início e o fim da fila
    vis[ar][ac] = 1; // marca a posição inicial como visitada
    fila[fim++] = (No){ar, ac, 0}; // adiciona a posição inicial à fila

    int resposta = 0; // variável para armazenar a resposta

    while (ini < fim) {
        No atual = fila[ini++]; // remove o primeiro elemento da fila

        if (atual.r == br && atual.c == bc) { // se o bloco atual é o bloco final, atualiza a resposta e sai do loop
            resposta = atual.dist; // atualiza a resposta com a distância do bloco inicial ao bloco final
            break;
        }

        for (int d = 0; d < 4; d++) { // loop para deslizar o bloco em todas as direções possíveis
            int tr, tc; // variáveis para armazenar a nova posição do bloco

            deslizar(map, n, m, atual.r, atual.c, dr[d], dc[d], &tr, &tc); // desliza o bloco na direção d

            if (!vis[tr][tc]) { // se a posição não foi visitada, marca como visitada e adiciona à fila
                vis[tr][tc] = 1;
                fila[fim++] = (No){tr, tc, atual.dist + 1}; // adiciona a nova posição à fila
            }
        }
    }

    printf("%d\n", resposta); // imprime a resposta

    free(fila);
    mapa_free(map, m, n, vis);
    return 0;
}