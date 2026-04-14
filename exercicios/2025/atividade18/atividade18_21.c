#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int qtdQuestoes; // variável para armazenar a quantidade de questões da prova
    int totalAlunos; // variável para armazenar o total de alunos que realizaram a prova
    int acertos = 0; // variável para contar o número de acertos do aluno, inicializada em 0 para cada aluno
    int i; // variável de controle para o loop interno

    if (scanf("%d %d", &qtdQuestoes, &totalAlunos) != 2 && !((qtdQuestoes <= 0 || totalAlunos < 0))) // valida a leitura dos dois inteiros e também verifica se os valores são válidos (qtdQuestoes deve ser maior que 0 e totalAlunos deve ser não negativo)
        return 0;

    // aloca memória para armazenar o gabarito e as respostas dos alunos, considerando a quantidade de questões. o tamanho é qtdQuestoes + 1 para incluir o caractere nulo '\0'
    char *gabarito = (char *)malloc((size_t)qtdQuestoes + 1);
    char *resp = (char *)malloc((size_t)qtdQuestoes + 1);
    if (!gabarito || !resp) {
        free(gabarito);
        free(resp);
        return 1;
    }

    double *notas = (double *)malloc((size_t)totalAlunos * sizeof(double));
    if (!notas) {
        free(gabarito);
        free(resp);
        return 1;
    }

    // Lê no máximo qtdQuestoes caracteres (sem contar '\0'), independente de ser 10, 7, etc.
    char fmt[32]; // buffer para armazenar a string de formato para scanf, garantindo que seja grande o suficiente para acomodar a quantidade de questões
    
    // a leitura " %%%ds" é feita para criar um formato dinâmico que se adapta à quantidade de questões, garantindo que o scanf leia exatamente a quantidade de caracteres esperada para o gabarito e as respostas dos alunos
    snprintf(fmt, sizeof fmt, " %%%ds", qtdQuestoes); // cria a string de formato dinamicamente, por exemplo, se qtdQuestoes for 10, fmt será " %10s"

    if (scanf(fmt, gabarito) != 1) { // lê o gabarito usando o formato criado. se a leitura falhar, libera a memória alocada e termina o programa
        free(notas);
        free(gabarito);
        free(resp);
        return 0;
    }

    double nota = 0.0; // variável para armazenar a nota do aluno, inicializada em 0.0 para cada aluno
    int lidos = 0; // variável para contar quantos alunos foram processados com sucesso, usada para controlar a impressão das notas posteriormente (redundante, mas mantém a lógica clara)

    for (int aluno = 0; aluno < totalAlunos; aluno++) { // loop para processar as respostas de cada aluno
        if (scanf(fmt, resp) != 1) // lê as respostas do aluno usando o mesmo formato. se a leitura falhar, interrompe o loop e passa para a etapa de liberação de memória
            break;

        acertos = 0; // reseta o contador de acertos para cada aluno antes de comparar as respostas com o gabarito
        for (i = 0; i < qtdQuestoes; i++) { // loop para comparar as respostas do aluno com o gabarito, contando o número de acertos
            if (resp[i] == gabarito[i]) 
                acertos++;
        }

        // calcula a nota do aluno com base na proporção de acertos em relação ao total de questões, multiplicando por 10 para obter a nota final (uso de casting para garantir que a divisão seja feita em ponto flutuante)
        nota = 10.0 * (double)acertos / (double)qtdQuestoes; 
        notas[lidos++] = nota;
    }

    for (int aluno = 0; aluno < lidos; aluno++) // loop para imprimir as notas dos alunos processados, usando o contador lidos para garantir que apenas as notas dos alunos que foram processados com sucesso sejam impressas
        printf("%.2f\n", notas[aluno]);
        
    free(notas);
    free(gabarito);
    free(resp);
    return 0;
}
