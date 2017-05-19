#include <bits/stdc++.h>

int main() {
	int n, i, qtd, numero[30];
	long long int valores[30], soma[30];

	valores[0] = soma[0] = 1;
	for(i = 1; i < 30; i++) {
		valores[i] = 3*valores[i-1];
		soma[i] = soma[i-1] + valores[i];
	}

	while(scanf("%d", &n) > 0) {
		qtd = 0;
		memset(numero, 0, sizeof(int)*30);
		
		for(i = 0; i < 30; i++)
			if(soma[i] >= abs(n))
				break;
		
		qtd = i;
		
		while(n != 0)
			for(i = 0; i < 30; i++)
				if(soma[i] >= abs(n)) {
					numero[i] = n < 0 ? -1 : n > 0 ? 1 : 0;
					n -= numero[i] * valores[i];
					break;
				}
		
		for(; qtd >= 0; qtd--)
			printf("%c", numero[qtd] == -1 ? '-' : numero[qtd] == 0 ? '0' : '+');
		
		printf("\n");
	}
}