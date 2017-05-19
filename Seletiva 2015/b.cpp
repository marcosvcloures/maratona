#include <stdio.h>

int pais[20000], geracao[20000] = {0}, qtd[20000] = {0}, estudou[20000] = {0};

int g(int a) {
	if(!geracao[a]) {
		geracao[a] = g(pais[a]) + 1;
	}
	
	return geracao[a];
}

int main() {
	int n, m, entrada, i, nGeracoes = 0;
	scanf("%d %d", &n, &m);
	
	for(i = 1; i <= n; i++) {
		scanf("%d", &entrada);
		pais[i] = entrada;
		
		if(entrada == 0)
			geracao[i] = 1;
	}
	
	for(i = 1; i <= n; i++) {
		g(i);
		
		if(geracao[i] > nGeracoes)
			nGeracoes = geracao[i];
		
		qtd[geracao[i]-1]++;
	}
	
	for(i = 0; i < m; i++) {
		scanf("%d", &entrada);
		estudou[geracao[entrada]-1]++;
	}
	
	printf("%.2lf", estudou[0]*100.0/qtd[0]);
	for(i = 1; i < nGeracoes; i++)
		printf(" %.2lf", estudou[i]*100.0/qtd[i]);
	printf("\n");
	
	return 0;
}