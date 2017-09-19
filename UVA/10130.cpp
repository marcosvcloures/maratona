#include <bits/stdc++.h>

using namespace std;

typedef struct {
	int valor, peso;
} tObjeto;

int pd[1001][31];

int main() {
	int t, n, i, j, g, p, soma;
	tObjeto objetos[1000];

	scanf("%d", &t);

	while (t--) {
		soma = 0;

		scanf("%d", &n);

		for (i = 0; i < n; i++)
			scanf("%d %d", &objetos[i].valor, &objetos[i].peso);

		for (i = 0; i <= 30; i++)
			pd[0][i] = 0;

		for (i = 1; i <= n; i++) {
			for (j = 1; j <= 30; j++)
				if (j < objetos[i-1].peso)
					pd[i][j] = pd[i - 1][j];
				else
					pd[i][j] = max(pd[i - 1][j], pd[i - 1][j - objetos[i-1].peso] + objetos[i-1].valor);
		}

		scanf("%d", &g);

		for (i = 0; i < g; i++)
			scanf("%d", &p), soma += pd[n][p];

		printf("%d\n", soma);
	}
}