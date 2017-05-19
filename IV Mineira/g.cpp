#include <stdio.h>
#include <stdlib.h>

long long int matrizAdj[20][20] = {0};

int main() {
	long long int n, m, x, t, a, b, v, i, j, k, *atuais, *proximos, soma;
	
	scanf("%lld %lld %lld", &n, &m, &x);
	
	while(m--) {
		scanf("%lld %lld %lld", &a, &b, &v);
		
		a--;
		b--;
		
		matrizAdj[a][b] = v;
		matrizAdj[b][a] = v;
	}
	
	scanf("%lld", &t);
	
	while(t--) {
		soma = 0;
		scanf("%lld %lld", &a, &b);
		
		a--;
		b--;
		
		atuais = (long long int *) calloc(sizeof(long long int), n);
		atuais[a] = 1;
		
		for(i = 0; i < x; i++) {
			proximos = (long long int *) calloc(sizeof(long long int), n);
			
			for(j = 0; j < n; j++) {
				if(atuais[j]) {
					for(k = 0; k < n; k++)
						if(matrizAdj[j][k])
							proximos[k] += atuais[j] * matrizAdj[j][k];
				}
			}
			
			free(atuais);
			atuais = proximos;
			
			soma += atuais[b];
		}
		
		printf("%lld\n", soma);
		free(atuais);
	}
}