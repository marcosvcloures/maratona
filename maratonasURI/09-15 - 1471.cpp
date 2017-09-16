#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, r, aux;
	
	bool voltou[10010], flag;
	
	while(scanf(" %d %d", &n, &r) > 0) {
		fill(voltou, voltou+n+1, false);
		
		for(int i=0; i<r; i++) {
			scanf(" %d", &aux);
			voltou[aux] = true;
		}
		
		if (r == n) {
			printf("*\n");
			continue;
		}		
		
		for(int i = 1; i <= n; i++) {
			if(!voltou[i])
				printf("%d ", i);
		}
		
		printf("\n");			
	}
}
