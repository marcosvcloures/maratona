#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll matriz[10][100], pd[10][100];
bool possiveis[10][100];

int main() {
	ll n, m, i, j, resp, sum;

	while (scanf("%lld %lld", &n, &m) > 0) {
		fill(pd[0], pd[0] + 10 * 100, 1ll << 40);
		fill(possiveis[0], possiveis[0] + 10 * 100, 0);

		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				scanf("%lld", &matriz[i][j]);

		for (i = 0; i < n; i++)
			pd[i][0] = matriz[i][0];

		for (j = 1; j < m; j++)
			for (i = 0; i < n; i++)
				pd[i][j] = min(pd[i][j - 1], min(pd[(i + 1) % n][j - 1], pd[(i + n - 1) % n][j - 1])) + matriz[i][j];

		for (resp = 1ll << 40, i = 0; i < n; i++)
			resp = min(resp, pd[i][m - 1]);

		for (i = 0; i < n; i++)
			possiveis[i][m - 1] = pd[i][m - 1] == resp;

		for (j = m - 2; j >= 0; j--)
			for (i = 0; i < n; i++)
				possiveis[i][j] = (possiveis[i][j + 1] && pd[i][j + 1] - pd[i][j] == matriz[i][j + 1])
				|| (possiveis[(i + 1) % n][j + 1] && pd[(i + 1) % n][j + 1] - pd[i][j] == matriz[(i + 1) % n][j + 1])
				|| (possiveis[(i + n - 1) % n][j + 1] && pd[(i + n - 1) % n][j + 1] - pd[i][j] == matriz[(i + n - 1) % n][j + 1]);

		for (i = 0; i < n; i++)
			if (possiveis[i][0]) {
				resp = i;
				break;
			}
		
		printf("%d", resp + 1);
		sum = matriz[resp][0];

		for (j = 1; j < m; j++)
			for (i = 0; i < n; i++)
				if ((i == resp || i == (resp + 1) % n || i == (resp + n - 1) % n) && sum + matriz[i][j] == pd[i][j] && possiveis[i][j]) {
					resp = i;
					sum += matriz[resp][j];
					printf(" %d", i + 1);
					break;
				}

		printf("\n%d\n", pd[resp][m - 1]);
	}
}