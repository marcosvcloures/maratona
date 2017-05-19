#include <bits/stdc++.h>

using namespace std;

int main() {
	long long int k, atual, tam;
	char entrada[30], val[30];
	
	while(scanf(" %s %lld", entrada, &k) > 0 && strcmp(entrada, "#")) {
		k--;
		
		tam = strlen(entrada);
		atual = 0;
		
		sort(entrada, entrada+tam);
		
		while(tam > 1) {			
			printf("%lld %lld %lld %c %s\n", k, tam-1, k/(tam-1), entrada[k/(tam-1)], entrada);
			
			val[atual] = entrada[k/(tam-1)];
			
			entrada[k/(tam-1)] = 'Z' + 1;
			
			k %= tam;
			
			sort(entrada, entrada+tam);
			
			atual++;
			tam--;
		}
		
		sort(entrada, entrada+1);
		val[atual] = entrada[0];
		val[atual+1] = 0;
		
		puts(val);
	}
}