#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, i, p[10000], lim, t = 0;
	double r, me;

	while (scanf("%d %d", &n, &m) > 0) {
		t++;
		r = me = 0;

		for (i = 0; i < m; i++)
			scanf("%d", &p[i]), me += p[i];

		me /= n;
		lim = n * 2;

		for (; i < lim; i++)
			p[i] = 0;

		sort(p, p + lim);

		printf("Set #%d\n", t);
		for (i = 0; i < n; i++) {
			printf(" %d:", i);

			if (p[i])
				printf(" %d", p[i]);
			if (p[lim - i - 1])
				printf(" %d", p[lim - i - 1]);

			r += fabs(me - p[i] - p[lim - i - 1]);

			printf("\n");
		}
		printf("IMBALANCE = %.5lf\n\n", r);
	}
}