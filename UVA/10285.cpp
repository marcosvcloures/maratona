#include <bits/stdc++.h>

using namespace std;

int mapa[102][102];
int pd[102][102];

int main() {
	int n, r, c, resp, i, j, k;
	char nome[1000];

	scanf("%d", &n);

	while (n--) {
		resp = 0;
		fill(mapa[0], mapa[0] + 102 * 102, 101);
		fill(pd[0], pd[0] + 102 * 102, 1); 

		scanf(" %s %d %d", nome, &r, &c);

		for (i = 1; i <= r; i++)
			for (j = 1; j <= c; j++)
				scanf("%d", &mapa[i][j]);

		for(k = 0; k <= 100; k++)
			for(i = 1; i <= r; i++)
				for (j = 1; j <= c; j++) {
					if (mapa[i][j] > mapa[i - 1][j])
						resp = max(resp, pd[i][j] = max(pd[i][j], pd[i - 1][j] + 1));
					if (mapa[i][j] > mapa[i + 1][j])
						resp = max(resp, pd[i][j] = max(pd[i][j], pd[i + 1][j] + 1));
					if (mapa[i][j] > mapa[i][j - 1])
						resp = max(resp, pd[i][j] = max(pd[i][j], pd[i][j - 1] + 1));
					if (mapa[i][j] > mapa[i][j + 1])
						resp = max(resp, pd[i][j] = max(pd[i][j], pd[i][j + 1] + 1));
				}

		printf("%s: %d\n", nome, resp);
	}
}