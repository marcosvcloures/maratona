#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m, k, i, j, maiorValor, maiorDist, inicio, dist;
	long long int entrada[30000], somas[30000];
	
	scanf("%d", &n);
	
	for(k = 1; k <= n; k++) {
		scanf("%d", &m);
		
		m--;
		
		for(i = 0; i < m; i++)
			scanf("%lld", &entrada[i]);
	
		maiorValor = somas[0] = entrada[0];
		
		maiorDist = inicio = 0;
		
		for(i = 1; i < m; i++) {
			if(somas[i-1] < 0)
				somas[i] = entrada[i];
			else
				somas[i] = somas[i-1] + entrada[i];
			
			if(somas[i] > maiorValor)
				maiorValor = somas[i];
		}
		
		if(maiorValor > 0) {
			for(i = 0; i < m; i++)
				if(somas[i] == maiorValor) {
					dist = 1;
					
					for(j = i; j >= 0 && somas[j] >= 0; j--)
						dist++;
						
					if(dist > maiorDist) {
						maiorDist = dist;
						inicio = j;
					}
				}
			
			printf("The nicest part of route %d is between stops %d and %d\n", k, inicio+2, inicio+dist+1);
		}
		else
			printf("Route %d has no nice parts\n", k);
	}
	
	return 0;
}