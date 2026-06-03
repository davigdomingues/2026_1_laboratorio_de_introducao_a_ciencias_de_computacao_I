#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { // estrutura para armazenar o sistema
    char **vetor; // vetor de strings para armazenar os nomes
    int tam; // tamanho do vetor
    int count; // número de elementos no vetor
} Sistema;

static void sistema_init(Sistema *s) { // função para inicializar o sistema
    s->tam = 1; // inicializa o tamanho do vetor com 1
    s->count = 0; // inicializa o número de elementos no vetor com 0
    s->vetor = malloc(sizeof(char *)); // aloca memória para o vetor
    if (s->vetor == NULL) exit(1);
}

static void sistema_free(Sistema *s) { // função para liberar a memória do sistema
    for (int i = 0; i < s->count; i++) // loop para liberar a memória de cada elemento do vetor
        free(s->vetor[i]);

    free(s->vetor); // libera a memória do vetor
}

static long long bytes_alocados(const Sistema *s) {
    long long b = (long long)s->tam * (long long)sizeof(char *); // calcula o número de bytes alocados para o vetor

    for (int i = 0; i < s->count; i++) // loop para calcular o número de bytes alocados para cada elemento do vetor
        b += (long long)strlen(s->vetor[i]) + 1; // adiciona o número de bytes alocados para cada elemento do vetor

    return b; // retorna o número de bytes alocados para o vetor
}

static int aumentar(Sistema *s) { // função para aumentar o tamanho do vetor
    if (s->count < s->tam) // se o número de elementos no vetor for menor que o tamanho do vetor, retorna 0
        return 0; // se o número de elementos no vetor for menor que o tamanho do vetor, retorna 0
    s->tam *= 2;

    char **novo = realloc(s->vetor, (size_t)s->tam * sizeof(char *)); // realoca o vetor para o novo tamanho
    if (novo == NULL) exit(1); // se a realocação falhar, sai do programa
    s->vetor = novo; // atualiza o vetor para o novo vetor

    return 1; // realocação foi bem-sucedida
}

static int diminuir(Sistema *s) { // função para diminuir o tamanho do vetor
    if (s->tam <= 1 || s->count != s->tam / 2) // se o tamanho do vetor for menor que 1 ou o número de elementos no vetor for diferente do tamanho do vetor
        return 0;

    s->tam /= 2;
    char **novo = realloc(s->vetor, (size_t)s->tam * sizeof(char *)); // realoca o vetor para o novo tamanho

    if (novo == NULL) exit(1); // se a realocação falhar, sai do programa
    s->vetor = novo;

    return 1;
}

static void cadastro(Sistema *s) { // função para cadastrar um novo nome
    char buf[31]; // buffer para armazenar o nome
    scanf("%30s", buf);

    int realocou = aumentar(s); // aumenta o tamanho do vetor se necessário

    size_t len = strlen(buf);
    s->vetor[s->count] = malloc(len + 1); // aloca memória para o nome

    if (s->vetor[s->count] == NULL) exit(1); // se a alocação falhar, sai do programa

    memcpy(s->vetor[s->count], buf, len + 1); // copia o nome para o vetor
    s->count++; // incrementa o número de elementos no vetor

    printf("%s\n", realocou ? "Realocacao" : "-"); // imprime a mensagem de realocação ou "-" se não foi necessário realocar
}

static void remocao(Sistema *s) { // função para remover um nome
    if (s->count == 0) { // se o número de elementos no vetor for 0, imprime "-" e retorna
        printf("-\n");
        return;
    }

    char nome[31];
    strcpy(nome, s->vetor[s->count - 1]); // copia o último nome para o buffer
    free(s->vetor[s->count - 1]); // libera a memória do último nome
    s->count--; // decrementa o número de elementos no vetor

    int realocou = diminuir(s); // diminui o tamanho do vetor se necessário
    printf("%s %s\n", nome, realocou ? "Realocacao" : "-");
}

static void relatorio(const Sistema *s) { // função para imprimir o relatório
    printf("%lld\n", bytes_alocados(s)); // imprime o número de bytes alocados para o vetor
}

int main(void) {
    int n; // variável para armazenar o número de operações
    scanf("%d", &n); // lê o número de operações

    Sistema s; // sistema para armazenar os nomes
    sistema_init(&s); // inicializa o sistema

    for (int i = 0; i < n; i++) { // loop para executar as operações
        int op; // variável para armazenar a operação
        scanf("%d", &op);

        switch (op) {
            case 1: // operação para cadastrar um novo nome
                cadastro(&s);
                break;

            case 2: // operação para remover um nome
                remocao(&s);
                break;

            case 3: // operação para imprimir o relatório
                relatorio(&s);
                break;
        }
    }

    sistema_free(&s); // libera a memória do sistema
    return 0;
}