#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
  Calculadora simples (versão alternativa, mais “robusta” no parsing).

  Diferenças principais vs. scanf direto:
  - Lê a linha inteira com fgets (evita ficar preso em entradas parciais).
  - Converte números com strtof, que fornece:
      * valor convertido
      * ponteiro 'end' para o primeiro caractere NÃO consumido
    Isso permite validar se realmente havia um número e continuar o parsing
    de forma controlada.

  Formato de entrada aceito:
    <float><espaços><op><espaços><float>[resto ignorado]
  Exemplos:
    2 + 3
    10.5/2
    -3.2   *   7

  Política de erros (retorno do programa):
    0  -> sucesso (imprime resultado com 2 casas)
    1  -> erro de leitura/parsing, operador inválido, ou divisão por zero
*/

typedef float (*op_fn)(float, float);

/* Implementações das operações (mantidas pequenas e puras). */
static float op_add(float a, float b) { return a + b; }
static float op_sub(float a, float b) { return a - b; }
static float op_mul(float a, float b) { return a * b; }
static float op_div(float a, float b) { return a / b; }

/*
  Tabela: caractere do operador -> função que executa a operação.

  Nuance: essa abordagem substitui o switch por “despacho por dados”.
  - Facilita adicionar novos operadores (basta inserir outro OpEntry).
  - Mantém o código principal sem múltiplos cases.
*/
typedef struct {
    char op;
    op_fn fn;
} OpEntry;

int main(void) {
    char linha[256];
    char *p, *end;
    float a, b, r;
    char op = '\0';

    const OpEntry ops[] = {
        {'+', op_add},
        {'-', op_sub},
        {'*', op_mul},
        {'/', op_div},
    };

    /*
      Lê 1 linha do stdin. Se não houver linha (EOF/erro), falha.
      Obs: fgets mantém o '\n' se couber no buffer, mas isso não atrapalha o parsing.
    */
    if (!fgets(linha, (int)sizeof(linha), stdin)) 
        return 1;

    p = linha;

    /*
      Parse do 1º número:
      - strtof(p, &end) tenta ler um float a partir de p.
      - Se end == p, nenhum caractere foi consumido => não havia número válido.
    */
    a = strtof(p, &end);
    if (end == p)
        return 1;
    p = end;

    /*
      Consome espaços antes do operador.
      isspace deve receber unsigned char convertido para evitar UB, com chars negativos em alguns ambientes/encodings.
    */
    while (*p && isspace((unsigned char)*p)) 
        p++;

    /*
      Lê o operador como um único caractere.
      aqui aceitamos exatamente um char como operador. Se a linha acabar, falha.
    */
    op = *p++;
    if (op == '\0')
        return 1;

    /*
      Parse do 2º número:
      - strtof já ignora espaços iniciais, então não é obrigatório pular espaços
    */
    b = strtof(p, &end);
    if (end == p)
        return 1;

    /*
      Despacho via tabela:
      - Procura o operador em ops[].
      - Ao encontrar, valida caso especial da divisão por zero e executa a função.
      - Imprime e encerra com sucesso.

      divisão por zero em float resulta em inf/NaN, no geral, mas aqui o exercício trata como erro (retorna 1).
    */
    for (size_t i = 0; i < sizeof(ops) / sizeof(ops[0]); i++) {
        if (ops[i].op == op) {
            if (op == '/' && b == 0.0f)
                return 1;

            r = ops[i].fn(a, b);
            printf("%.2f\n", r);

            return 0;
        }
    }

    /* Se percorreu a tabela e não encontrou, o operador é inválido. */
    return 1;
}