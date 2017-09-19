#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, i;
	char saida[1031441], temp[1031441];
	
	while(scanf("%d", &n) > 0) {
		sprintf(saida, "-");
		
		for(i = 0; i < n; i++) {
			strcpy(temp, saida);
			sprintf(saida, "%s%*c%s", temp, strlen(temp), ' ', temp);
		}
		
		puts(saida);
	}
}