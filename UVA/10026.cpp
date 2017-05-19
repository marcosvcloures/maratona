#include <bits/stdc++.h>

using namespace std;

int t, n, primeiro = true, trabalhos[1000][2], posicoes[1000], i;

bool comp(int a, int b) {
	return trabalhos[a][0] * trabalhos[b][1] < trabalhos[b][0] * trabalhos[a][1];
}

int main() {	
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		for (i = 0; i < n; i++)
			scanf("%d %d", &trabalhos[i][0], &trabalhos[i][1]), posicoes[i] = i;

		stable_sort(posicoes, posicoes + n, comp);

		printf("%s%d", primeiro ? "" : "\n", posicoes[0] + 1);
		
		for (i = 1; i < n; i++)
			printf(" %d", posicoes[i] + 1);
		
		printf("\n");

		primeiro = false;
	}
}