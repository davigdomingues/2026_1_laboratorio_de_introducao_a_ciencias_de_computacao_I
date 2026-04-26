#include <stdio.h>
#include <stdbool.h>

int main(void) {
	char letra, mensagem[100];
	int numero;
	bool atingido = false;

	scanf(" %c%d", &letra, &numero);
	scanf(" %100s", mensagem);

	for (int i = 0; mensagem[i] != '\0' && mensagem[i + 1] != '\0'; i += 2) {
		if (mensagem[i] == letra && (mensagem[i + 1] - '0') == numero) { // verifica se a letra e o número correspondem
			atingido = true;
			break;
		}
	}

	if (atingido) printf("Fomos atingidos!\n");
	else printf("Oceano tranquilo!\n");

	return 0;
}