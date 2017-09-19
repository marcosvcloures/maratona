#include <bits/stdc++.h>

using namespace std;

char matriz[102][102], temp[102][102];

int flood(int i, int j) {	
	if(temp[i][j] == 'W') {
		int resp = 1;
		
		temp[i][j] = 'L';
		
		for(int ii = -1; ii <= 1; ii++)
			for(int jj = -1; jj <= 1; jj++)
				resp += flood(i + ii, j + jj);
			
		return resp;
	}
	else
		return 0;
}

int main() {
	int n = 1, i, j, fimlinha, primeiro = true;
	char entrada[102];
	
	scanf("%*d");
	
	while(scanf(" %[^\n]", entrada) > 0) {
		if(entrada[0] == 'L' || entrada[0] == 'W') {
			fill(matriz[n], matriz[n] + 102, 'L');
			
			copy(entrada, entrada + strlen(entrada), matriz[n++] + 1);
			
			fimlinha = true;
		}
		else {
			n = 1;
			
			if(fimlinha && !primeiro)
				printf("\n");
			
			fimlinha = primeiro = false;
			
			sscanf(entrada, "%d %d", &i, &j);
			
			copy(matriz[0], matriz[0] + 102 * 102, temp[0]);
			
			printf("%d\n", flood(i, j));
		}
	}
}