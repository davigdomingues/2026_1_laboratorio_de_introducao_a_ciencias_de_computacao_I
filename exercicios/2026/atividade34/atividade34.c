#include <stdio.h>

int main(void) {
	int hp;
	char ataques[100];

	scanf("%d", &hp);
	scanf("%100s", ataques);

	for (int i = 0; ataques[i] != '\0'; i++) {
		if (ataques[i] == 'C') hp -= 30; // ataque crítico
		else if (ataques[i] == 'A') hp -= 10; // ataque normal

		if (hp <= 0) { // o personagem desmaiou
			printf("Desmaiou\n");
			return 0;
		}
	}

	printf("Sobreviveu com %d HP\n", hp);
	return 0;
}