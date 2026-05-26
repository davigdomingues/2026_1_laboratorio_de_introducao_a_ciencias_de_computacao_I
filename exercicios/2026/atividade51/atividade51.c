#include <stdio.h>
#include <string.h>

int main() {
    int n, m; // n = tamanho do treinamento, m = número de previsões a fazer
    char training[10001]; // string de treinamento
    char initial; // caractere inicial para a previsão

    scanf("%d", &n);
    scanf("%s", training);
    scanf("%d", &m);
    scanf(" %c", &initial);

    // Matriz para contar as ocorrências: count[i][j] = quantas vezes a letra (j) segue a letra (i)
    // i = letra anterior, j = letra seguinte
    // índice 0 = 'a', índice 1 = 'b', etc.
    int count[26][26];
    memset(count, 0, sizeof(count));

    // Construção da matriz de contagens a partir do treinamento
    for (int i = 0; i < n - 1; i++) {
        int prev = training[i] - 'a';  // índice da letra anterior
        int next = training[i + 1] - 'a';  // índice da letra seguinte
        count[prev][next]++;
    }

    // String para armazenar o resultado
    char result[10001];
    result[0] = initial;
    int result_len = 1;

    // Faz as previsões
    char current = initial;
    for (int i = 0; i < m; i++) {
        int current_idx = current - 'a'; // índice da letra atual

        // Procura-se qual é o caractere mais frequente após current
        int max_count = count[current_idx][0];
        char next_char = 'a';

        for (int j = 1; j < 26; j++) {
            if (count[current_idx][j] > max_count) {
                max_count = count[current_idx][j];
                next_char = 'a' + j;
            } 
            
            else if (count[current_idx][j] == max_count) {
                // empate -> menor letra
                if (('a' + j) < next_char) next_char = 'a' + j;
            }
        }
        
        // Adiciona o caractere previsto ao resultado
        result[result_len] = next_char;
        result_len++;
        
        // Decrementa a contagem dessa sequência
        int next_idx = next_char - 'a';
        count[current_idx][next_idx]--;
        
        // Atualiza current para o próximo caractere
        current = next_char;
    }
    
    // Nulifica o final da string
    result[result_len] = '\0';

    printf("%s\n", result);
    
    return 0;
}