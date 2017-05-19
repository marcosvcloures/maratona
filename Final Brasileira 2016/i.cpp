#include <bits/stdc++.h>

using namespace std;

int n, b, c, cidades[6000], inicio[6000], fim[6000], melhor[6000][6000];

int main() {
	int i, j;
	vector<int> casas;
	
	scanf("%d %d %d", &n, &b, &c);
	
	for(i = 0; i < n; i++) {
		scanf("%d", &cidades[i]);
		
		inicio[i] = casas.size();
		
		for(j = 0; j < cidades[i]; j++)
			casas.push_back(i);
		
		for(j = i; j >= 0; j--)
			custo[i][j] = casas[(casas.size() - inicio[j]) / 2], printf("m %d %d = %d\n", j, i, melhor[i][j]);
		
		fim[i] = casas.size();
	}
}