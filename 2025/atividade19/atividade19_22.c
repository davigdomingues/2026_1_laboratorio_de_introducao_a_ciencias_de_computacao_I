#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

static int naipe_idx(char n) { // função para obter o índice do naipe a partir do caractere lido, onde 'C' representa Copas, 'O' representa Ouros, 'P' representa Paus e 'E' representa Espadas. a função retorna um valor entre 0 e 3 para os naipes válidos ou -1 para um naipe inválido
    switch (toupper((unsigned char)n)) {
        case 'C': 
            return 0; // Copas

        case 'O': 
            return 1; // Ouros

        case 'P': 
            return 2; // Paus

        case 'E': 
            return 3; // Espadas

        default: 
            return -1;
    }
}

static int valor_idx(const char *v) { // função para obter o índice do valor da carta a partir da string lida, onde "A" representa Ás, "2" a "10" representam os valores numéricos correspondentes, "J" representa Valete, "Q" representa Dama e "K" representa Rei. a função retorna um valor entre 0 e 12 para os valores válidos ou -1 para um valor inválido
    if (!v || !*v) 
        return -1;

    if (strcmp(v, "A") == 0) // verifica se a string lida é "A", representando o Ás, e retorna o índice 0 para mapear o Ás para o índice 0 na matriz de contagem de cartas
        return 0;

    if (strcmp(v, "J") == 0) // verifica se a string lida é "J", representando o Valete, e retorna o índice 10 para mapear o Valete para o índice 10 na matriz de contagem de cartas
        return 10;

    if (strcmp(v, "Q") == 0) // verifica se a string lida é "Q", representando a Dama, e retorna o índice 11 para mapear a Dama para o índice 11 na matriz de contagem de cartas
        return 11;

    if (strcmp(v, "K") == 0) // verifica se a string lida é "K", representando o Rei, e retorna o índice 12 para mapear o Rei para o índice 12 na matriz de contagem de cartas
        return 12;


    char *end = NULL; // ponteiro para armazenar o endereço do primeiro caractere inválido encontrado durante a conversão da string para um número inteiro usando strtol, permitindo verificar se a string representa um número válido e se não contém caracteres extras
    long num = strtol(v, &end, 10); // converte a string v para um número inteiro usando base 10, armazenando o resultado em num e o endereço do primeiro caractere inválido em end, permitindo verificar se a conversão foi bem-sucedida e se a string representa um número válido

    if (*end != '\0') // verifica se a string contém caracteres extras após a conversão para um número inteiro, indicando que a string não representa um número válido, e retorna -1 para indicar um valor inválido
        return -1;

    if (num >= 2 && num <= 10)  // verifica se o número convertido está dentro do intervalo válido para as cartas numéricas (2 a 10), retornando o índice correspondente (número - 1) para mapear os valores de 2 a 10 para os índices de 1 a 9, respectivamente
        return (int)num - 1; // 2->1 ... 10->9

    return -1;
}

int main() {
    int cartas[4][13] = {0}; // matriz para armazenar a contagem de cada carta, onde o primeiro índice representa o naipe (0 a 3) e o segundo índice representa o valor da carta (0 a 12)
    char C = 0, O = 0, P = 0, E = 0; // variáveis para armazenar os caracteres representando os naipes (C: ouros, O: paus, P: copas, E: espadas)
    cartas[0][0] = C; // inicializa a contagem da carta de ouros (naipe 1, valor 1) em 0
    cartas[1][0] = O; // inicializa a contagem da carta de paus (naipe 2, valor 1) em 0
    cartas[2][0] = P; // inicializa a contagem da carta de copas (naipe 3, valor 1) em 0
    cartas[3][0] = E; // inicializa a contagem da carta de espadas (naipe 4, valor 1) em 0
    char valorCarta; // variável para armazenar o valor da carta lida, que pode variar de 1 a 13 (representando as cartas de Ás a Rei)
    char naipeCarta; // variável para armazenar o caractere do naipe da carta lida, que pode ser 'C', 'O', 'P' ou 'E'

    // Lê cartas até EOF aceitando tanto "AC"/"10O"/"QE" quanto "10 O" (valor e naipe separados).
    char tok[8], tok2[8], val[8]; // arrays de caracteres para armazenar os tokens lidos da entrada, onde tok é usado para ler o token atual, tok2 é usado para ler o próximo token quando o valor e o naipe estão separados, e val é usado para armazenar o valor da carta extraído do token lido, garantindo que haja espaço suficiente para armazenar os valores das cartas (como "10") e os naipes (como "O")
    while (scanf(" %7s", tok) == 1) { // lê um token da entrada, que pode ser o valor e o naipe juntos (como "10O") ou apenas o valor (como "10") seguido do naipe em um token separado (como "O"), até o final do arquivo (EOF)
        char n = 0; // variável para armazenar o caractere do naipe da carta lida, inicializada em 0 para indicar que ainda não foi determinado
        val[0] = '\0'; // inicializa a string val para armazenar o valor da carta, garantindo que esteja vazia antes de copiar o valor lido

        size_t len = strlen(tok); // calcula o comprimento do token lido para determinar se ele contém tanto o valor quanto o naipe (como "10O") ou apenas o valor (como "10")
        if (len >= 2 && naipe_idx(tok[len - 1]) != -1) { // verifica se o último caractere do token é um naipe válido (C, O, P ou E) e se o comprimento do token é suficiente para conter um valor antes do naipe, indicando que o token contém tanto o valor quanto o naipe (como "10O")
            n = tok[len - 1];
            memcpy(val, tok, len - 1); // copia o valor da carta do token para a string val, excluindo o último caractere que representa o naipe, garantindo que val contenha apenas o valor da carta (como "10") para ser processado posteriormente
            val[len - 1] = '\0'; // adiciona um caractere nulo ao final da string val para garantir que ela seja uma string válida em C, terminando a string após o valor da carta e antes do naipe, permitindo que a função valor_idx processe corretamente o valor da carta
        }
        
        else { // caso contrário, assume que o token contém apenas o valor (como "10") e que o próximo token lido será o naipe (como "O"), então copia o valor para val e lê o próximo token para obter o naipe
            strcpy(val, tok); // copia o valor da carta do token para a string val, garantindo que val contenha o valor da carta (como "10") para ser processado posteriormente

            if (scanf(" %7s", tok2) != 1) 
                break;

            n = tok2[0]; // assume que o próximo token contém o naipe e armazena o primeiro caractere do token em n, que representa o naipe da carta lida, permitindo que a função naipe_idx processe corretamente o naipe da carta
        }

        int ni = naipe_idx(n); // obtém o índice do naipe usando a função naipe_idx, que retorna um valor entre 0 e 3 para os naipes válidos (C, O, P, E) ou -1 para um naipe inválido
        int vi = valor_idx(val); // obtém o índice do valor da carta usando a função valor_idx, que retorna um valor entre 0 e 12 para os valores válidos (A, 2-10, J, Q, K) ou -1 para um valor inválido

        if (ni != -1 && vi != -1) // verifica se tanto o naipe quanto o valor da carta são válidos antes de atualizar a contagem na matriz cartas, garantindo que apenas cartas válidas sejam contabilizadas
            cartas[ni][vi]++; // incrementa a contagem da carta correspondente na matriz cartas, onde ni é o índice do naipe e vi é o índice do valor da carta, permitindo contar quantas vezes cada carta foi lida da entrada
    }

    const char *naipes[4] = {"Copas", "Ouros", "Paus", "Espadas"}; // array de strings para representar os nomes dos naipes, onde o índice corresponde ao valor retornado pela função naipe_idx (0 para Copas, 1 para Ouros, 2 para Paus e 3 para Espadas)
    const char *vals[13]  = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"}; // array de strings para representar os valores das cartas, onde o índice corresponde ao valor retornado pela função valor_idx (0 para A, 1 para 2, ..., 9 para 10, 10 para J, 11 para Q e 12 para K)

    printf("\n"); // imprime uma linha em branco para separar a saída da contagem de cartas da entrada lida, melhorando a legibilidade da saída
    for (int n = 0; n < 4; n++) { // loop para iterar sobre os naipes, onde n é o índice do naipe, permitindo imprimir a contagem de cada carta para cada naipe
        printf("\nNaipe : %s\n", naipes[n]);

        for (int v = 0; v < 13; v++) { // loop para iterar sobre os valores das cartas, onde v é o índice do valor da carta, permitindo imprimir a contagem de cada carta para o naipe atual
            if (v == 0 || v >= 10)
                printf("%s : %d\n", vals[v], cartas[n][v]);

            else
                printf("%s: %d\n",  vals[v], cartas[n][v]);
        }
    }

    return 0;
}
