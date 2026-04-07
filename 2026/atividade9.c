#include <stdio.h>
#include <string.h>

int main()
{
    int numero1, numero2;
    char operacao;
    
    scanf("%d %d %c", &numero1, &numero2, &operacao);
    
    switch (operacao) {
        case '+': printf("%d", numero1 + numero2); break;
        case '-': printf("%d", numero1 - numero2); break;
        case '*': printf("%d", numero1 * numero2); break;
        
        case '/':
            if (numero2 == 0) printf("Erro: divisao por zero");
            else printf("%.2f", (float) numero1 / numero2);
            break;
            
        default: printf("Erro: operacao invalida"); break;
    }

    return 0;
}
