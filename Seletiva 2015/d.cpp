#include <stdio.h>

int matrizAdj[20000][20000] = {0}, graus[20000] = {0};

void remove(int maior, int n) {
	for(int i = 0; i < n; i++) {
		if(matrizAdj[maior][i]) {
			graus[i]--;
			matrizAdj[maior][i] = 0;
			matrizAdj[i][maior] = 0;
		}
		
		graus[maior] = 0;
	}
}

int main() {
	int n, m, qtd, continua, i, a, b, maior = 0;
	
	scanf("%d %d", &n, &m);
	
	qtd = n;
	
	for(i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		
		a--;
		b--;
		
		matrizAdj[a][b] = 1;
		matrizAdj[b][a] = 1;
		
		graus[a]++;
		
		if(graus[a] > graus[maior])
			maior = a;
		
		graus[b]++;
		
		if(graus[b] > graus[maior])
			maior = b;
	}
	
	remove(maior, n);
	qtd--;
	continua = 1;
	
	while(continua) {
		continua = false;
		
		for(i = 0; i < n; i++)
			if(graus[i] == 1) {
				remove(i, n);
				continua = true;
				qtd--;
			}
	} 
	
	printf("%d\n", qtd);
}