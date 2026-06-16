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
    if (scanf("%s", nome_arquivo) != 1) return 1;

    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) return 1;

    double n1, n2, n3, n4, soma_total = 0.0, nota_final, media = 0.0;
    char codigo[256], melhor_codigo[256] = "", pior_codigo[256] = "";
    int melhor_nota_int = -1, pior_nota_int = 1001, aprovados = 0, total_alunos = 0, nota_final_int;    
    int freq[101] = {0}; // Array de contagem (0 a 100) para calcular a moda
    
    // Processamento do CSV linha por linha
    while (fscanf(arquivo, " %[^,],%lf,%lf,%lf,%lf", codigo, &n1, &n2, &n3, &n4) == 5) { // O espaço antes do %[^,] consome as quebras de linha pendentes
        media = (n1 + n2 + n3 + n4)/4.0;
        
        // Arredondamento para baixo considerando somente uma casa decimal
        nota_final_int = (int)(media*10); 
        nota_final = nota_final_int/10.0;
        
        // Maior nota: em caso de empate, o primeiro lido seja mantido
        if (nota_final_int > melhor_nota_int) {
            melhor_nota_int = nota_final_int;
            copiar_string(melhor_codigo, codigo);
        }
        
        // Menor nota: em caso de empate, o primeiro lido seja mantido
        if (nota_final_int < pior_nota_int) {
            pior_nota_int = nota_final_int;
            copiar_string(pior_codigo, codigo);
        }
        
        // Controle de aprovação
        if (nota_final_int >= 50) aprovados++;
        
        // Acúmulo para a média total
        soma_total += nota_final;
        total_alunos++;
        
        // Frequência para a moda
        freq[nota_final_int]++;
    }

    fclose(arquivo);

    if (total_alunos == 0) return 0;

    // Cálculo final da moda iterando sobre as frequências
    int max_freq = 0, moda_int = 0;
    for (int i = 0; i <= 100; i++) { // 100 é a nota máxima multiplicada por 10, garantindo que os números sejam inteiros (1 casa decimal)
        if (freq[i] > max_freq) { // Se houver empate, o menor valor será a moda
            max_freq = freq[i];
            moda_int = i;
        }
    }

    // Padrão: 1 casa para notas e 2 para a porcentagem
    printf("%s %.1f\n", melhor_codigo, melhor_nota_int/10.0);
    printf("%s %.1f\n", pior_codigo, pior_nota_int/10.0);
    printf("%.2f%%\n", ((double)aprovados/total_alunos)*100.0);
    printf("%.1f\n", soma_total/total_alunos);
    printf("%.1f\n", moda_int/10.0);

    return 0;
}