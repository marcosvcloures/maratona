#include <bits/stdc++.h>

using namespace std;

int lc[2000][2000];

int main() {
	char pa[2000], pb[2000];
	int ta, tb, i, j;

	while (fgets(pa, 2000, stdin)) {
		fgets(pb, 2000, stdin);
		
		ta = strlen(pa) - 1;
		tb = strlen(pb) - 1;

		for (i = 0; i <= ta; i++) 
			fill(lc[i], lc[i] + tb + 1, 0);
		
		for(i = 1; i <= ta; i++)
			for (j = 1; j <= tb; j++) 
				if (pa[i - 1] == pb[j - 1])
					lc[i][j] = max(lc[i - 1][j - 1] + 1, max(lc[i - 1][j], lc[i][j - 1]));
				else
					lc[i][j] = max(lc[i - 1][j], lc[i][j - 1]);
			
		printf("%d\n", lc[ta][tb]);
	}
}