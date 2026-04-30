#include <stdio.h>

int main() {
    int a1, a2, a3, n;
    scanf("%d %d %d", &a1, &a2, &a3);

    int *arq[3] = {&a1, &a2, &a3}, rem[3] = {0, 0, 0};
    scanf("%d", &n);

    while (n--) { // loop para ler as operações
        int op, i, j, x;
        scanf("%d", &op);

        if (op == 1) { // atualizacao
            scanf("%d %d", &i, &x);
            i--;
            if (!rem[i]) *arq[i] = x; // atualiza o valor do arquivo se não foi removido
        } 
        
        else if (op == 2) { // remoção
            scanf("%d", &i);
            i--;
            if (!rem[i]) rem[i] = 1;
        } 
        
        else { // op == 3, organização
            scanf("%d %d", &i, &j);
            i--; j--;

            // operação swap, se os arquivos não forem removidos
            if (!rem[i] && !rem[j]) {
                int tmp = *arq[i];
                *arq[i] = *arq[j];
                *arq[j] = tmp;
            }
        }
    }

    for (int k = 0; k < 3; k++) {
        if (rem[k]) printf("NULL"); // arquivo removido
        else printf("%d", *arq[k]); // arquivo não removido
        if (k < 2) printf(" "); // espaço entre os arquivos
    }

    printf("\n");

    return 0;
}