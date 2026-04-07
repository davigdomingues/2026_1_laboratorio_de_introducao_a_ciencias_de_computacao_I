#include <stdio.h>

static void swap_ptr(int **p, int **q) { // função para trocar os ponteiros de dois cartões usando ponteiros para ponteiros
    int *tmp = *p;
    *p = *q;
    *q = tmp;
}

int main(void) {
    int livro1, livro2, livro3; // variáveis para armazenar os valores dos livros 1, 2 e 3, respectivamente

    if (scanf("%d %d %d", &livro1, &livro2, &livro3) != 3)
        return 0;

    int *cartao[3] = { &livro1, &livro2, &livro3 }; // array de ponteiros para os cartões, inicialmente apontando para os livros correspondentes

    for (int i = 0; i < 3; i++) { // loop para ler as ações para cada cartão
        int acao;

        if (scanf("%d", &acao) != 1) 
            return 0;

        switch (acao) { // switch para tratar as ações de forma mais clara e eficiente
            case -1: // ação para retirar o livro da estante, ou seja, tornar o cartão NULL
                cartao[i] = NULL;
                break;

            case 0: // ação para colocar o livro de volta na estante, ou seja, incrementar o valor do livro correspondente ao cartão, se o cartão não for NULL
                if (cartao[i]) (*cartao[i])++;
                break;

            // ações para trocar o livro do cartão atual com o livro do cartão indicado pela ação (1, 2 ou 3), usando a função swap_ptr
            case 1:
            case 2:
            case 3:
                swap_ptr(&cartao[i], &cartao[acao - 1]);
                break;

            default:
                break; // ignora
        }
    }

    for (int i = 0; i < 3; i++) { // loop para imprimir o estado final dos cartões
        printf("cartao%d -> ", i + 1);

        if (!cartao[i]) 
            printf("Livro fora da estante\n");

        else 
            printf("%d\n", *cartao[i]);
    }

    return 0;
}