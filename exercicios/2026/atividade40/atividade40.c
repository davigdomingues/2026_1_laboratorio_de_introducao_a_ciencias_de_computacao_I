#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    long long termo;

    if (N % 3 == 1) { // se o resto da divisao de N por 3 for 1
        // posições 1,4,7,...: 2,4,8,16,...
        int k = (N + 2)/3; // calcula o numero de termos
        termo = 1;
        for (int i = 0; i < k; i++)
            termo *= 2;
    } 
    
    else if (N % 3 == 2) { // se o resto da divisao de N por 3 for 2
        // posições 2,5,8,...: 7,21,63,...
        int k = (N + 1)/3; // calcula o numero de termos
        termo = 7;
        for (int i = 1; i < k; i++)
            termo *= 3;
    } 
    
    else { // se o resto da divisao de N por 3 for 0
        // posições 3,6,9,...: 3,12,48,...
        int k = N/3; // calcula o numero de termos
        termo = 3;
        for (int i = 1; i < k; i++)
            termo *= 4;
    }

    printf("%lld\n", termo);
    return 0;
}