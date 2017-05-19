#include <bits/stdc++.h>

bool achei;

bool procurar(int *sol, int a, int b, int c, int n) {
	int i;

	if (achei)
		return true;
	else if (n > 3)
		return false;
	else if (n == 3) {
		if (sol[0] + sol[1] + sol[2] == a &&
			sol[0] * sol[1] * sol[2] == b &&
			sol[0] * sol[0] + sol[1] * sol[1] + sol[2] * sol[2] == c) {
			printf("%d %d %d\n", sol[0], sol[1], sol[2]);
			achei = true;
			return true;
		}

		return false;
	}

	for (i = -sqrt(c); i < sqrt(c); i++) {
		if (n > 0 && sol[n - 1] >= i)
			continue;

		sol[n] = i;

		procurar(sol, a, b, c, n + 1);
	}
}

int main() {
	int n, sol[3], a, b, c;

	scanf("%d", &n);

	while (n--) {
		scanf("%d %d %d", &a, &b, &c);

		achei = false;

		procurar(sol, a, b, c, 0);

		if (!achei)
			puts("No solution.");
	}

	return 0;
}