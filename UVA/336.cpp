#include <bits/stdc++.h>

using namespace std;

int main(){
	int nc, i, j, k, n, matriz[40][40], caso = 1, r, o, a, b;
	
	map<int, int> mapa;
	
	while(scanf("%d", &nc) && nc) {
		n = 0;
		fill(matriz[0], matriz[0] + 40 * 40, 1 << 20);
		mapa.clear();
		
		for(i = 0; i < nc; i++) {
			scanf("%d %d", &a, &b);
			
			if(!mapa.count(a))
				mapa[a] = n++;
			if(!mapa.count(b))
				mapa[b] = n++;
				
			a = mapa[a];
			b = mapa[b];
				
			matriz[a][b] = matriz[b][a] = 1;
		}
		
		for(i = 0; i < n; i++)
			matriz[i][i] = 0;
		
		for(k = 0; k < n; k++)
			for(i = 0; i < n; i++)
				for(j = 0; j < n; j++)
					if(matriz[i][k] + matriz[k][j] < matriz[i][j])
						matriz[i][j] = matriz[i][k] + matriz[k][j];
						
		while(scanf("%d %d", &o, &b) && (o || b)) {
			a = mapa[o];
			r = 0;
			
			for(i = 0; i < n; i++)
				if(matriz[a][i] > b)
					r++;
					
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", caso++, r, o, b);
		}
	}

	return 0;
}
