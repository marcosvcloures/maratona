#include <bits/stdc++.h>

using namespace std;

int matrizAdj[100][100] = {0};

bool chegavel (int atual, int desejado, int n, int proibido, int visitados[]) {
	if(atual == desejado) 
		return true;
	
	visitados[atual] = 1;

	for(int i = 0; i < n; i++)
		if(i == proibido || visitados[i])
			continue;
		else if (matrizAdj[atual][i] && chegavel(i, desejado, n, proibido, visitados)) 
			return true;
			
	return false;
}

bool domina(int a, int b, int n) {
	int visitados1[100] = {0}, visitados2[100] = {0};
	
	if(a == 0)
		return chegavel(0, b, n, a, visitados1);
	
	if(chegavel(0, b, n, -1, visitados1))
		return !chegavel(0, b, n, a, visitados2);
	
	return false;
}

int main() {
	int t, n, count, i, j;
	
	scanf("%d", &t);
	
	for(count = 1; count <= t; count++) {
		scanf("%d", &n);
		
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%d", &matrizAdj[i][j]);
		
		printf("Case %d:\n", count);		
		
		for(i = 0; i < n; i++) {
			printf("+");
			for(j = 0; j < 2*n - 1; j++)
				printf("-");
			printf("+\n");
			
			for(j = 0; j < n; j++) 
				printf("|%c", domina(i, j, n) ? 'Y' : 'N');
			printf("|\n");
		}
		
		printf("+");
		
		for(i = 0; i < 2*n - 1; i++)
			printf("-");
		
		printf("+\n");
	}
}