#include <bits/stdc++.h>

using namespace std;

int main() {
	int valores[100], entrada, maximo, count, i, j, n, primeiro = true;

	while (scanf("%d", &entrada) > 0) {
		n = count = 0;
		maximo = entrada;

		do {
			valores[n] = entrada;
			n++;
			maximo = max(maximo, entrada);
		} while (scanf("%d", &entrada) && entrada);

		for (i = 1; i <= maximo; i++) {
			for (j = n - 1; j >= 0; j--) {
				if (valores[j] < i)
					break;
			}

			for (; j >= 0; j--)
				if (valores[j] >= i)
					count++;
		}
		
		sort(valores, valores + n);

		if (!primeiro)
			printf("\n");
		else
			primeiro = false;

		for (i = 0; i < n; i++) {
			for (j = 0; j < valores[i]; j++)
				printf("X");

			for (; j < maximo; j++)
				printf("-");

			printf(" > %d\n", valores[i]);
		}

		printf("A total of %d beads slid during the sort.\n", count);
	}
}