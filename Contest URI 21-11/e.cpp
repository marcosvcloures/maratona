#include <bits/stdc++.h>

using namespace std;

int mat[100][100], n, resp = 0, maxi = 0;

void bk(int i, int j, int dir) {
	if(j < 0)
		return bk(i+1, 0, !dir);
	if(j == n)
		return bk(i+1, n-1, !dir);
	
	if(i == n) {
		maxi = max(maxi, resp);
		return;
	}
	
	if (mat[i][j] == 'A')
		maxi = max(maxi, resp), resp = 0;
	
	if(mat[i][j] == 'o')
		resp++;
	
	if(dir == 1) 
		return bk(i, j+1, dir);
	return bk(i, j-1, dir);
}

int main() {	
	int i, j;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++) 
		for(j = 0; j < n; j++)
			scanf(" %c", &mat[i][j]);
	
	bk(0, 0, 1);
	
	printf("%d\n", maxi);
}