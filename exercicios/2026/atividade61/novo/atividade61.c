#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função com aritmética de ponteiros para substituir strcpy
void copiar_string(char *dest, const char *src) {
    while (*src) *dest++ = *src++;
    *dest = '\0';
}

int main() {
    char nome_arquivo[256];
    // Lê o nome do arquivo da entrada padrão
    if (scanf("%s", nome_arquivo) != 1) return 1;

    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) return 1;

    double n1, n2, n3, n4, nota_final, melhor_nota = -1.0, pior_nota = 11.0, soma_total_geral = 0.0;
    char codigo[256], melhor_codigo[256] = "", pior_codigo[256] = "";
    int aprovados = 0, total_alunos = 0;

    // Processamento do CSV linha por linha
    while (fscanf(arquivo, " %[^,],%lf,%lf,%lf,%lf", codigo, &n1, &n2, &n3, &n4) == 5) {
        nota_final = (n1 + n2 + n3 + n4) / 4.0; 

        // Maior nota: em caso de empate, o uso de '>' estrito mantém o primeiro lido
        if (nota_final > melhor_nota) {
            melhor_nota = nota_final;
            copiar_string(melhor_codigo, codigo);
        }

        // Menor nota: em caso de empate, o uso de '<' estrito mantém o primeiro lido
        if (nota_final < pior_nota) {
            pior_nota = nota_final;
            copiar_string(pior_codigo, codigo);
        }

        // Controle de aprovação
        if (nota_final >= 5.0) aprovados++;

        soma_total_geral += nota_final;
        total_alunos++;
    }

    fclose(arquivo);

    if (total_alunos == 0) return 0;

    // Cálculo da porcentagem e média geral
    double porcentagem_aprovacao = ((double)aprovados/total_alunos)*100.0, media_geral = soma_total_geral/total_alunos;

    // Impressão exata das quatro linhas solicitadas, delegando o arredondamento ao printf
    printf("%s %.1lf\n", melhor_codigo, melhor_nota);
    printf("%s %.1lf\n", pior_codigo, pior_nota);
    printf("%.2lf%%\n", porcentagem_aprovacao);
    printf("%.1lf\n", media_geral);

    return 0;
}