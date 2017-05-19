#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, maiores[500], pos[500], val[500], off, i, j;

	while (scanf("%d", &n) > 0 && n) {
		for (i = 0; i < n; i++) {
			scanf("%d", &maiores[i]);

		memset(val, 0, sizeof(int) * n);

		for (i = 0; i < n; i++) {
			for (j = off = 0; j < maiores[i]; j++)
				while (val[j + off])
					off++;

			while (val[j + off])
				off++;

			val[j + off] = i + 1;
		}

		printf("%d", val[0]);
		for (i = 1; i < n; i++)
			printf(",%d", val[i]);
		printf("\n");
	}
}