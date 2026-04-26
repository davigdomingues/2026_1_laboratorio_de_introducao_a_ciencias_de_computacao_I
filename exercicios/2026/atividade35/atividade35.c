
#include <stdio.h>

int main() {
	char s[200];
	if (scanf("%199s", s) != 1) return 0;

	int miku = 0, teto = 0;

	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i + 3] == '\0') break;

		if (s[i] == 'M' && s[i + 1] == 'I' && s[i + 2] == 'K' && s[i + 3] == 'U') miku++;

		if (s[i] == 'T' && s[i + 1] == 'E' && s[i + 2] == 'T' && s[i + 3] == 'O') teto++;
	}

	if (miku > teto) printf("Miku\n");
	else if (teto > miku) printf("Teto\n");
	else printf("Empate\n");

	return 0;
}
