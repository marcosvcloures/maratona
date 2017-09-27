#include <bits/stdc++.h>

using namespace std;

int matriz1[500][500], matriz2[500][500], matriz3[500][500], matriz4[500][500], (*pdB_v)[500], (*pdB_n)[500], (*pdP_v)[500], (*pdP_n)[500];

int main() {
	int n, p, i, j, d, l, c, qtdp = 0, qtdb = 0;
	
	pdB_n = matriz1;
	pdB_v = matriz2;
	pdP_n = matriz3;
	pdP_v = matriz4;
	
	scanf("%d %d", &n, &p);
	
	memset(pdB_n, 0, 500*500*sizeof(int));
	memset(pdP_n, 0, 500*500*sizeof(int));
	
	for(i = 0; i < p; i++)
		scanf("%d %d", &l, &c), pdP_n[l-1][c-1] = 1, qtdp++;

	for(i = 0; i < p; i++)
		scanf("%d %d", &l, &c), pdB_n[l-1][c-1] = 1, qtdb++;
	
	for(d = 1; d < n; d++) {
		swap(pdB_n, pdB_v);
		swap(pdP_n, pdP_v);
		
		memset(pdB_n, 0, 500*500*sizeof(int));
		memset(pdP_n, 0, 500*500*sizeof(int));
		
		for(i = 0; i < n-d; i++) 
			for(j = 0; j < n-d; j++) {
				pdB_n[i][j] = (pdB_v[i][j] + pdB_v[i][j+1] + pdB_v[i+1][j] + pdB_v[i+1][j+1]) > 0;
				pdP_n[i][j] = (pdP_v[i][j] + pdP_v[i][j+1] + pdP_v[i+1][j] + pdP_v[i+1][j+1]) > 0;
				
				if(pdB_n[i][j] && pdP_n[i][j] == 0)
					qtdb++;
				else if(pdP_n[i][j] && pdB_n[i][j] == 0)
					qtdp++;
			}
	}
	
	printf("%d %d\n", qtdp, qtdb);
}