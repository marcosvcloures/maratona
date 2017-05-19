#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, val[20000], picos, i;

	while (scanf(" %d", &n) > 0 && n) {
		picos = 0;

		for (i = 0; i < n; i++)
			scanf("%d", &val[i]);

		val[n] = val[0];
		val[n + 1] = val[1];
		
		for (i = 1; i < n + 1; i++) 
			if ((val[i - 1] > val[i] && val[i] < val[i + 1]) ||
				(val[i - 1] < val[i] && val[i] > val[i + 1]))
				picos++;

		printf("%d\n", picos);
	}
}