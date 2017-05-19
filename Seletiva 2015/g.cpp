#include <stdio.h>
#include <math.h>

int matriz[1024][1024];

int conta(int ii, int ji, int n) {
	int i, j, c = 0, atual;
	
	atual = matriz[ii][ji];
	
	for(i = ii; i < ii+n; i++) {
		for(j = ji; j < ji+n; j++)
			if(matriz[i][j] != atual) {
				c += conta(ii, ji, n/2);
				c += conta(ii, ji+n/2, n/2);
				c += conta(ii+n/2, ji, n/2);
				c += conta(ii+n/2, ji+n/2, n/2);
				
				return c;
			}
	}
	
	return 1;
}

int main() {
	int n;
	
	scanf("%d", &n);
	
	n = pow(2, n);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf(" %c", &matriz[i][j]);
	
	printf("%d\n", conta(0, 0, n));
}