#include <bits/stdc++.h>

using namespace std;

int qtd[70][2];

int main() {
	int n, resp, a, i;
	char e;
	
	while(scanf("%d", &n) > 0) {
		fill(qtd[0], qtd[0] + 140, 0);
		resp = 0;
		
		while(n--) {
			scanf("%d %c", &a, &e);
		
			if(e == 'D')
				qtd[a][1]++;
			else
				qtd[a][0]++;
		}
		
		for(i = 0; i < 70; i++)
			resp += min(qtd[i][0], qtd[i][1]);
			
		printf("%d\n", resp);
	}
}
