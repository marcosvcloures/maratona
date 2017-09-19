#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, e, aux, best;
	
	while(scanf("%d", &n) && n) {
		best = -1;
		aux = 0;
		
		while(n--) {
			scanf("%d", &e);
			
			aux += e;
			
			if(aux > best)
				best = aux;
			else if(aux < 0)
				aux = 0;
		}
		
		if(best > 0)
			printf("The maximum winning streak is %d.\n", best);
		else
			puts("Losing streak.");
	}
	
	return 0;
}
