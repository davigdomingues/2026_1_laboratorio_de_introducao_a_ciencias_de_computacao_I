#include <stdio.h>

int main(void) {
	int n;

	if (scanf("%d", &n) != 1)
		return 0;

	int zeros = 0;
	for (int p = 5; p <= n; p *= 5)
		zeros += n / p;

	printf("%d\n", zeros);
	return 0;
}