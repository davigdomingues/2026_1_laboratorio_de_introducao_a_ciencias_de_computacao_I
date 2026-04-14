#include <stdio.h>

int main() {
    char nome1[19], nome2[19];
    int i;
    
    scanf("%s", nome1);
    scanf("%s", nome2);
    
    for (i = 0; nome1[i] != '\0' && nome2[i]; i++) {
        if (nome1[i] != nome2[i]) {
            printf("Nao sou eu");
            return 0;
        }
    }
    
    // verificação se ambos os nomes se encerraram juntos (evita falso positivo)
    if (nome1[i] == '\0' && nome2[i] == '\0') printf("Sou eu");
    else printf("Nao sou eu");
    
    return 0;
}
