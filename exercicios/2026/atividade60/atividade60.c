#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Estrutura que decompõe a data
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// Estrutura de matrícula contendo nome dinâmico
typedef struct {
    char *nome;
    Data data;
} Matricula;

// Estrutura do Sistema para encapsular o controle de memória
typedef struct {
    Matricula *lista;
    int tamanho;
    int capacidade;
} Sistema;

// Inicializa o sistema de alocação dinâmico para as matrículas
void inicializar_sistema(Sistema *s) {
    s->tamanho = 0;
    s->capacidade = 2;
    s->lista = (Matricula *)malloc(s->capacidade * sizeof(Matricula));
}

// Lê e cria uma nova matrícula
void adicionar_matricula(Sistema *s) {
    char buffer[256];
    Data d;

    scanf("%s", buffer);
    scanf("%d/%d/%d", &d.dia, &d.mes, &d.ano);

    if (s->tamanho >= s->capacidade) {
        s->capacidade *= 2;
        s->lista = (Matricula *)realloc(s->lista, s->capacidade * sizeof(Matricula));
    }

    s->lista[s->tamanho].nome = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(s->lista[s->tamanho].nome, buffer);

    s->lista[s->tamanho].data = d;
    s->tamanho++;
}

// Busca a data de matrícula de um aluno pelo nome
void buscar_por_nome(const Sistema *s) {
    char buffer[256];
    scanf("%s", buffer);

    for (int i = 0; i < s->tamanho; i++) {
        if (strcmp(s->lista[i].nome, buffer) == 0) {
            printf("%02d/%02d/%02d\n", s->lista[i].data.dia, s->lista[i].data.mes, s->lista[i].data.ano);
            return;
        }
    }

    printf("N/A\n");
}

// Busca todos os nomes matriculados em uma data específica
void buscar_por_data(const Sistema *s) {
    Data d;
    scanf("%d/%d/%d", &d.dia, &d.mes, &d.ano);

    bool encontrou = false;
    for (int i = 0; i < s->tamanho; i++) {
        if (s->lista[i].data.dia == d.dia &&
            s->lista[i].data.mes == d.mes &&
            s->lista[i].data.ano == d.ano) {

            if (encontrou) printf(" ");

            printf("%s", s->lista[i].nome);
            encontrou = true;
        }
    }

    if (!encontrou) printf("N/A");
    printf("\n"); 
}

// Limpa toda a memória
void liberar_sistema(Sistema *s) {
    for (int i = 0; i < s->tamanho; i++) free(s->lista[i].nome);
    free(s->lista);
}

int main() {
    Sistema sis;
    inicializar_sistema(&sis);

    // Loop para processar as operações até o EOF ou operação 0
    int operacao;
    while (scanf("%d", &operacao) != EOF && operacao != 0) {
        if (operacao == 1) adicionar_matricula(&sis);
        else if (operacao == 2) buscar_por_nome(&sis);
        else if (operacao == 3) buscar_por_data(&sis);
    }

    liberar_sistema(&sis);
    return 0;
}