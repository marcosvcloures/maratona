#include <stdio.h>

int main() {
	int matrizAdj[100][100], n, m, a, b, max = 0, i, j, k;
	
	scanf("%d %d", &n, &m);
	
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			matrizAdj[i][j] = 20;
		
	while(m--) {
		scanf("%d %d", &a, &b);
		
		matrizAdj[a-1][b-1] = 1;
		matrizAdj[b-1][a-1] = 1;
	}

	for(k = 0; k < n; k++)
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				if(matrizAdj[i][j] > matrizAdj[i][k] + matrizAdj[k][j])
					matrizAdj[i][j] = matrizAdj[i][k] + matrizAdj[k][j];
				
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(matrizAdj[i][j] > max)
				max = matrizAdj[i][j];
	
	printf("%c\n", max > 6 ? 'N' : 'S');
}