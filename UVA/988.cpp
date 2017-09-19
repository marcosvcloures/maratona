#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi grafo;
vi possibilidades;

int pd(int atual) {
	if (possibilidades[atual] != -1)
		return possibilidades[atual];

	int resp = 0;

	for (auto it : grafo[atual])
		resp += pd(it);

	return possibilidades[atual] = resp;
}

int main() {
	int n, m, e, p = 1;
	
	while (scanf("%d", &n) > 0) {
		grafo = vvi(n);
		possibilidades = vi(n);
		
		if (!p)
			printf("\n");
		else
			p = 0;
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &m);
			
			if (m == 0)
				possibilidades[i] = 1;
			else {
				possibilidades[i] = -1;

				for (int j = 0; j < m; j++)
					scanf("%d", &e), grafo[i].push_back(e);
			}
		}

		printf("%d\n", pd(0));
	}
}