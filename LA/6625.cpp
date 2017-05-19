#include <bits/stdc++.h>

using namespace std;

int col[8];
int mat[8][8] = {0};
int k, n, q;

int calc(int l, int c) {
	if(l == k && c > col[l])
		return 1;
	if(c > col[l])
		return calc(l+1, 1);
	
	int i = max(max(l, mat[l-1][c]+1), mat[l][c-1]), r = 0;
	
	if(i > n)
		return 0;
	
	for(; i <= n; i++)
		mat[l][c] = i, r += calc(l, c+1);
	
	return r;
}

int main() {
	int i;
	
	while(scanf("%d", &k) > 0) {
		memset(mat, 0, sizeof(int) * 8 * 8);
		
		for(i = 1; i <= k; i++)
			scanf("%d", &col[i]);
		
		scanf("%d", &n);
		
		printf("%d\n", calc(1, 1));
	}
	
	return 0;
}