#include <bits/stdc++.h>

using namespace std;

int t, l, e, livros[1000], pos[1000], ini, fim, sum;

bool pode(int v) {
	int i, usados = 1;

	for (i = sum = 0; i < l; i++)
		if (livros[i] > v)
			return false;
		else if (sum + livros[i] <= v)
			sum += livros[i];
		else
			sum = livros[i], usados++;

	return usados <= e;
}

int main() {
	int i, j;

	scanf("%d", &t);

	while (t--) {
		ini = fim = 0;

		scanf("%d %d", &l, &e);

		for (i = 0; i < l; i++)
			scanf("%d", &livros[i]), fim += livros[i];

		for (i = 0; i < 100; i++)
			if (pode((ini + fim) / 2))
				fim = (ini + fim) / 2;
			else
				ini = (ini + fim) / 2;

		for (i = l - 1, j = e - 2, sum = 0; i >= 0; i--) {
			 if (j == i)
				pos[j] = i, j--;
			 else if (sum + livros[i] <= fim)
				sum += livros[i];
			else
				sum = livros[i], pos[j] = i, j--;
		}

		printf("%d%s", livros[0], pos[0] == 0 ? " /" : "");
		for (i = 1, j = (pos[0] == 0); i < l; i++)
			printf(" %d%s", livros[i], pos[j] == i ? " /" : ""), j += pos[j] == i;
		printf("\n");
	}
}