#include <bits/stdc++.h>

using namespace std;

char matriz[100][100], terra;
int n, m;

int ff(int i, int j) {
	if(matriz[i][j] != terra)
		return 0;
		
	matriz[i][j] = 0;
	
	if(i == 0)
		return 1 + ff(i + 1, j) + ff(i, (j + 1) % m) + ff(i, (m + j - 1) % m);
	if(i == n - 1)
		return 1 + ff(i - 1, j) + ff(i, (j + 1) % m) + ff(i, (m + j - 1) % m);
		
	return 1 + ff(i + 1, j) + ff(i - 1, j) + ff(i, (j + 1) % m) + ff(i, (m + j - 1) % m);
}

int main(){
	int r, i, j, x, y, primeiro = 1;
	
	while(scanf("%d %d", &n, &m) > 0) {		
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				scanf(" %c", &matriz[i][j]);
				
		scanf("%d %d", &x, &y);
		
		terra = matriz[x][y];
		
		ff(x, y);
		
		r = 0;
		
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				if(matriz[i][j] == terra)
					r = max(r, ff(i, j));
					
		printf("%d\n", r);
		
	}

	return 0;
}
