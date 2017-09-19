#include <bits/stdc++.h>

using namespace std;

int matrizAdj[300][300] = {0};
int corNodos[300] = {0};

int bicoloravel(int n) {
	corNodos[0] = 1;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(corNodos[i] && matrizAdj[i][j]) {
				if(corNodos[j] == corNodos[i])
					return false;
				corNodos[j] = corNodos[i] == 1 ? 2 : 1;
			}
			
	return true;
}

int main () {
	int n, m, a, b, i, j;
	
	while(scanf("%d", &n) && n != 0) {
		scanf("%d", &m);
		
		while(m--) {
			scanf("%d %d", &a, &b);
			
			matrizAdj[a][b] = matrizAdj[b][a] = 1;
		}
		
		printf("%sBICOLORABLE.\n", bicoloravel(n) ? "" : "NOT ");
		
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++)
				matrizAdj[i][j] = matrizAdj[i][j] = 0;
			corNodos[i] = 0;
		}
	}
}