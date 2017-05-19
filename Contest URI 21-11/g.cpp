#include <bits/stdc++.h>

using namespace std;

int main() {	
	int tam, n, prim, prox, maxi, i;
	
	scanf("%d %d", &tam, &n);
	
	scanf("%d", &prim);
	
	maxi = prim-1;
	
	if(n > 1) {
		for(i = 1; i < n-1; i++) {
			scanf("%d", &prox);
			
			maxi = max(maxi, (prox-prim) / 2);
			
			swap(prox, prim);
		}
		
		scanf("%d", &prox);
		
		maxi = max(maxi, (prox-prim) / 2);
		
		maxi = max(maxi, tam-prox);
	}
	else {
		maxi = max(maxi, tam-prim);
	}
	
	printf("%d\n", maxi);
}