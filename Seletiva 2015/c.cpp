#include <stdio.h>

int main() {
	int n, saltos[200000] = {0}, atual, maior, entrada, i;
	
	while(scanf("%d", &n) > 0) {
		atual = maior = 0;
		
		for(i = 0; i < n; i++) {
			scanf("%d", &entrada);
			saltos[i] = entrada-atual;
			
			if(saltos[i] > maior)
				maior = saltos[i];
			
			atual = entrada;
		}
		
		atual = maior;
		
		for(i = 0; i < n; i++) {
			if(saltos[i] == atual && atual != 1)
				atual--;
			else if(saltos[i] > atual) {
				maior++;
				break;
			}
		}
		
		printf("%d\n", maior);
	}
}