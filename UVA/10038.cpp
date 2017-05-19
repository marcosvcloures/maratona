#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, i, velho, atual, foi, usados[30000];

	while (scanf(" %d", &n) > 0) {
		memset(usados, 0, n * sizeof(int));

		scanf("%d", &velho);

		for (i = 1; i < n; velho = atual, i++)
			scanf("%d", &atual), usados[abs(velho - atual)] = 1;

		for(i = 1, foi = true; i < n; i++)
			if (usados[i] == 0) {
				foi = false;
				break;
			}

		printf("%s\n", foi ? "Jolly" : "Not jolly");
	}
}