#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, val[1000], i, maxdif[2];

	while (scanf("%d", &n) > 0) {
		maxdif[0] = maxdif[1] = 0;

		for (i = 0; i < n; i++)
			scanf("%d", &val[i]);

		sort(val, val + n);

		for (i = 0; i < n - 1; i += 2)
			maxdif[0] += val[i + 1] - val[i];

		maxdif[1] = 24 - val[n - 1] + val[0];

		for (i = 1; i < n - 1; i += 2)
			maxdif[1] += val[i + 1] - val[i];

		printf("%d\n", min(maxdif[0], maxdif[1]));
	}
}