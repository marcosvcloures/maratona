#include <bits/stdc++.h>

using namespace std;

int main() {
	int p, m, v, n, i, e, val[10000];

	scanf("%d", &p);

	while (p--) {
		scanf("%d %d", &v, &n);

		printf("%d %d\n", v, (n + 1) / 2);

		for (i = 0; i < n; i++) {
			scanf("%d", &val[i]);

			if (i % 2 == 0) {
				sort(val, val + i + 1);

				if (i % 20 == 0 && i != 0)
					printf("\n%d", val[i / 2]);
				else if (i == 0)
					printf("%d", val[0]);
				else
					printf(" %d", val[i / 2]);
			}
		}

		printf("\n");
	}
}