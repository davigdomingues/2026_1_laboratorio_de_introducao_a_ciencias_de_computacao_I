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

    double n1, n2, n3, n4;
    char codigo[256], melhor_codigo[256] = "", pior_codigo[256] = "";
    int melhor_nota_int = -1, pior_nota_int = 1001, aprovados = 0, total_alunos = 0, nota_final_int, soma_total_exata_int = 0; 
    int freq[101] = {0}; // Array de contagem (0 a 100) para calcular a moda
    
    // Processamento do CSV linha por linha
    while (fscanf(arquivo, " %[^,],%lf,%lf,%lf,%lf", codigo, &n1, &n2, &n3, &n4) == 5) {
        int n1_i = (int)(n1 * 10.0 + 0.5), n2_i = (int)(n2 * 10.0 + 0.5), n3_i = (int)(n3 * 10.0 + 0.5), n4_i = (int)(n4 * 10.0 + 0.5);
        
        int soma_das_4_notas = n1_i + n2_i + n3_i + n4_i;
        nota_final_int = soma_das_4_notas/4.0; 
        
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
        
        // Soma do valor exato na média global, não a nota truncada do aluno, para garantir a precisão
        soma_total_exata_int += soma_das_4_notas;
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

    // A divisão inteira finaliza a média da turma garantindo o truncamento
    int media_geral_int = (soma_total_exata_int/4.0) / total_alunos;

    // Padrão: 1 casa para notas e 2 para a porcentagem
    printf("%s %.1f\n", melhor_codigo, melhor_nota_int/10.0);
    printf("%s %.1f\n", pior_codigo, pior_nota_int/10.0);
    printf("%.2f%%\n", ((double)aprovados/total_alunos)*100.0);
    printf("%.1f\n", media_geral_int/10.0);
    printf("%.1f\n", moda_int/10.0);

    return 0;
}