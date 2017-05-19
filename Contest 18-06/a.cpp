#include <bits/stdc++.h>

using namespace std;

int log10(int a) {
	int resp = 0;
	
	while(a) {
		resp++;
		a /= 10;
	}
	
	return resp;
}

int digito(int a, int b) {
	char resp[20];
	
	sprintf(resp, "0000%d", a);
	
	return resp[strlen(resp)-b]-'0';	
}

int existe(int resp, int b, int v) {
	v /= 4;
	
	return log10(resp)-(log10(b) + v) >= 0;
}

int main() {
	int a, b, i, j, qtdLinhas, qtdColunas, qtdDigitos, resp;
	
	while(scanf("%d %d", &a, &b) > 0 && (a || b)) {
		qtdColunas = log10(a)*4+5;
		qtdLinhas = log10(b)*4+5;
		qtdDigitos = log10(resp = a * b);
		
		for(i = 0; i < qtdLinhas; i++) {
			for(j = 0; j < qtdColunas; j++) {
				if(i == 0 && (j == 0 || j == qtdColunas-1) || i == qtdLinhas-1 && (j == 0 || j == qtdColunas-1))
					printf("+");
				else if(i == 0 || i == qtdLinhas-1)
					printf("-");
				else if(j == 0 || j == qtdColunas-1)
					printf("|");
				else if(j % 4 == 0 && i == 1)
					printf("%d", digito(a, (qtdColunas-j)/4));
				else if(j == 1 && i % 4 == 1 && existe(resp, a, qtdLinhas-i) > 0)
					printf("%d", digito(resp, (log10(a) + (qtdLinhas-i)/4)));
				else if(i == qtdLinhas-2 && j % 4 == 3 && j < qtdColunas-5)
					printf("%d", digito(resp, (qtdColunas-j)/4));
				else if(i == 1)
					printf(" ");
				else if(i % 4 == 0 && j == qtdColunas-2)
					printf("%d", digito(b, (qtdLinhas-i)/4));
				else if(j == qtdColunas-2)
					printf(" ");
				else if(i % 4 == 0 && j % 4 == 0 || i % 4 == 1 && j % 4 == 3 || i % 4 == 3 && j % 4 == 1 && j != 1 && i != qtdLinhas-2 || j == 1 && existe(resp, a, qtdLinhas-i+5) > 0 && i % 4 == 3 || i == qtdLinhas-2 && j % 4 == 1 && j < qtdColunas-5 && existe(resp, 0, qtdColunas-j) > 0)
					printf("/");
				else if(i % 4 == 2 && j % 4 == 2)
					printf("+");
				else if(i % 4 == 2 && j > 2 && j < qtdColunas-3)
					printf("-");
				else if(j % 4 == 2 && i > 2 && i < qtdLinhas-3)
					printf("|");
				else if(j > 2 && j < qtdColunas-3 && i < qtdLinhas-3 && i % 4 == 3 && j % 4 == 3 )
					printf("%d", digito(digito(a, (qtdColunas-j)/4) * digito(b, (qtdLinhas-i)/4), 2));
				else if(j > 2 && j < qtdColunas-3 && i % 4 == 1 && j % 4 == 1) 
					printf("%d", digito(digito(a, (qtdColunas-j)/4) * digito(b, (qtdLinhas-i)/4), 1));
				else
					printf(" ");
			}
			
			printf("\n");
		}
	}
}