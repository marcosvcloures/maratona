#include <stdio.h>

long long int estrelas[2000000] = {0}, visitados[2000000] = {0};

int main() {
	long long int n, total = 0, nvisitados = 0, atual, i;
	
	scanf("%lld", &n);
	
	for(i = 0; i < n; i++) {
		scanf("%lld", &estrelas[i]);
		total += estrelas[i];
	}
	
	atual = 0;
	
	while(atual >= 0 && atual < n) {
		if(!estrelas[atual])
			break;
		
		if(!visitados[atual]) {
			visitados[atual] = 1;
			nvisitados++;
		}
		
		estrelas[atual]--;
		total--;
		
		if(estrelas[atual] % 2)
			atual--;
		else
			atual++;		
	}
	
	printf("%lld %lld\n", nvisitados, total);
}