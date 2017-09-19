#include <bits/stdc++.h>
using namespace std;

int matriz[21][21], soma, c, pd[21][201];

int back(int proxPeca, int dinheiro) {
	if (pd[proxPeca][dinheiro] != -1)
		return pd[proxPeca][dinheiro];
	if (dinheiro < 0)
		return 1 << 30;
	if (proxPeca == c)
		return dinheiro;
	else {
		int resp = 1 << 30;

		for (int j = 1; j <= matriz[proxPeca][0]; j++)
			resp = min(resp, back(proxPeca + 1, dinheiro - matriz[proxPeca][j]));

		return pd[proxPeca][dinheiro] = resp;
	}
}

int main() {
	int t, m, k, resp;

	cin >> t;

	while (t--) {

		cin >> m >> c;

		for (int i = 0; i < c; i++) {
			cin >> k;
			matriz[i][0] = k;
			for (int j = 1; j <= k; j++)
				cin >> matriz[i][j];
		}

		fill(pd[0], pd[0] + 21 * 201, -1);

		resp = back(0, m);

		if (resp == 1 << 30)
			cout << "no solution" << endl;
		else
			cout << m - resp << endl;
	}

	return 0;
}