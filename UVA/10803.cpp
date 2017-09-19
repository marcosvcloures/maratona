#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

double dist[100][100];

int main() {
	int n, x, y, caso = 1;
	double maxi;
	vii cidades;

	scanf("%*d");

	while (scanf("%d", &n) > 0) {
		cidades.clear();
		fill(dist[0], dist[0] + 100 * 100, 1e10);

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);

			cidades.push_back(ii(x, y));

			for (int j = 0; j < i; j++) {
				int dist2 = (cidades[j].first - x) * (cidades[j].first - x) + (cidades[j].second - y) * (cidades[j].second - y);

				if (dist2 <= 100)
					dist[i][j] = dist[j][i] = sqrt(dist2);
			}
		}

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (dist[i][k] + dist[k][j] < dist[i][j])
						dist[i][j] = dist[i][k] + dist[k][j];

		maxi = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				maxi = max(maxi, dist[i][j]);

		if (maxi == 1e10)
			printf("Case #%d:\nSend Kurdy\n\n", caso++);
		else
			printf("Case #%d:\n%.4lf\n\n", caso++, maxi);
	}
}