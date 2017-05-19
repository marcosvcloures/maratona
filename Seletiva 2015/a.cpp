#include <stdio.h>

int main() {
	char letras[200002] = {0}, letra;
	int proximo[200002] = {0}, n, atual, prox, i;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++) {
		scanf("%d %c %d", &atual, &letra, &prox);
		letras[atual] = letra;
		proximo[atual] = prox;
	}
	
	printf("%c", letras[0]);
	atual = proximo[0];
	
	while(atual != 1) {
		printf("%c", letras[atual]);
		atual = proximo[atual];
	}
	
	printf("\n");

	return 0;
}