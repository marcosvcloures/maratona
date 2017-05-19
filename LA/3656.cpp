#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, e, i, par[2], impar[2];

	while (scanf("%d", &n) && n) {
		par[0] = par[1] = impar[0] = impar[1] = 0;

		for (i = 0; i < n; i++)
			scanf("%d", &e), e & 1 ? impar[0]++ : par[0]++;

		for (i = 0; i < n; i++)
			scanf("%d", &e), e & 1 ? impar[1]++ : par[1]++;
	
		printf("%d\n", max(0, n - min(impar[0], par[1]) - min(impar[1], par[0])));
	}
}