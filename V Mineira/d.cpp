#include <bits/stdc++.h>

int comb[20][20] = {0};

int main() {
	int i, j;
	
	comb[1][1] = 1;
	
	for(i = 1; i < 20; i++) 
		for(j = 2; j < 20; j++) 
			comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
}