#include <stdio.h>

int main() {
	int n, atual = 1, sentido = 1;
	char entrada;
	
	scanf("%d", &n);
	
	scanf(" %c", &entrada);
	
	while(entrada != '#') {
		if(atual > n) 
			atual = 1;
		else if(atual < 1) 
			atual = n;
		
		if(entrada == '?') {
			printf("%d ", atual);
			scanf(" %c", &entrada);
			continue;
		}
		else if(entrada == 'A' || entrada == '7') {
			atual += sentido;
			
			if(atual > n) 
				atual = 1;
			else if(atual < 1) 
				atual = n;
		}
		else if(entrada == 'Q')
			sentido *= -1;
		
		atual += sentido;
		
		scanf(" %c", &entrada);
	}
	
	printf("\n");
}