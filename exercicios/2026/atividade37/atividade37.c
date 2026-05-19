#include <stdio.h>

int main() {
    int n;
    long long primeiro, anterior, atual, soma = 0;

    scanf("%d", &n);
    scanf("%lld", &primeiro);
    anterior = primeiro;

    for (int i = 1; i < n; i++) {
        scanf("%lld", &atual);
        soma += anterior * atual;
        anterior = atual;
    }

    soma += anterior * primeiro;
    printf("%lld\n", soma);

    return 0;
}