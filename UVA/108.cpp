#include <bits/stdc++.h>

using namespace std;

int entrada[100][100], somas[100][100];

int main() {
	int n, maior = -(1<<30), i, j, k, l;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &entrada[i][j]);
			
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			somas[i][j] = entrada[i][j];
			
			if(somas[i][j] > maior)
				maior = somas[i][j];
			
			for(k = i+1; k < n; k++) {
				somas[k][j] = entrada[k][j] + somas[k-1][j];
				
				if(somas[k][j] > maior)
					maior = somas[k][j];
			}		
			
			for(k = j+1; k < n; k++) {
				somas[i][k] = entrada[i][k] + somas[i][k-1];
				
				if(somas[i][k] > maior)
					maior = somas[i][k];
			}
			
			for(k = i+1; k < n; k++) 
				for(l = j+1; l < n; l++) {
					somas[k][l] = entrada[k][l] + somas[k-1][l] + somas[k][l-1] - somas[k-1][l-1];
					
					if(somas[k][l] > maior)
						maior = somas[k][l];
				}
		}
	
	printf("%d\n", maior);
}