#include <stdio.h>

/* para esse problema, o número de zeros no final de n! é determinado pelo número de fatores de 10 em n!, 
   e cada fator de 10 é composto por um fator de 2 e um fator de 5. 
   Como geralmente há mais fatores de 2 do que de 5 em n!, o número de zeros no final de n! 
   é igual ao número de fatores de 5 em n!. Para calcular isso, podemos contar quantos múltiplos 
   de 5, 25, 125, etc. existem em n!.
*/

int main(void) {
	int n; // variável para armazenar o valor de n

	if (scanf("%d", &n) != 1)
		return 0;

	int zeros = 0; // variável para contar o número de zeros no final de n!
	for (int p = 5; p <= n; p *= 5)
		zeros += n / p; // cálculo do número de múltiplos de 5, 25, 125, etc. em n!

	printf("%d\n", zeros);
	return 0;
}