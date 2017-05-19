#include <bits/stdc++.h>

using namespace std;

int main() {
	int v, m, valores[200000] = {0}, i, e;
	
	scanf("%d %d", &v, &m);
	
	valores[v] = 1;
	
	while(m--) {
		scanf("%d", &e);
		
		if(valores[e]) {
			puts("S");
			return 0;
		}
		
		for(i = e + 1; i <= v; i++)
			valores[i-e] = max(valores[i-e], valores[i]);
	}
	
	puts("N");
}