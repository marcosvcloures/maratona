#include <bits/stdc++.h>

using namespace std;

int main() {
	int qtd[10000][10] = { 0 }, i, t, n;

	for (i = 1; i < 10000; i++) {
		for (t = 0; t < 10; t++)
			qtd[i][t] = qtd[i - 1][t];
		for (t = i; t; t /= 10)
			qtd[i][t % 10]++;
	}

	scanf("%d", &n);
	
	while (n--) {
		scanf("%d", &t);

		printf("%d", qtd[t][0]);
		for (i = 1; i < 10; i++)
			printf(" %d", qtd[t][i]);
		printf("\n");
	}
}