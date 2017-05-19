#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, i, atual = 0, resp = 0, entrada;
	map<int, int> casas;
	
	scanf("%d %d", &n, &m);
	
	for(i = 0; i < n; i++)
		scanf("%d", &entrada), casas[entrada] = i;
	
	for(i = 0; i < m; i++) {
		scanf("%d", &entrada);
		
		resp += abs(casas[entrada] - atual);
		atual = casas[entrada];
	}
	
	printf("%d\n", resp);
}