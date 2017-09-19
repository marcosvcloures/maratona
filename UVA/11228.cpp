#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000;
long long Rank[maxn], p[maxn], n;
double custoA, custoB;

void init(int _n) {
	n = _n;
	custoA = custoB = 0;

	fill(Rank, Rank + n, 0);
	for (int i = 0; i < n; i++) p[i] = i;
}

int find(int x) {
	return x == p[x] ? x : (p[x] = find(p[x]));
}

bool unir(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;

	if (Rank[a] < Rank[b]) swap(a, b);
	if (Rank[a] == Rank[b]) ++Rank[a];
	p[b] = a;

	return true;
}

int main() {
	long long n, r, i, j, x, y, resp, caso = 1, r2;
	vector< pair<long long, pair<long long, long long > > > arestas;
	vector< pair<long long, long long > > vertices;

	scanf("%*d");

	while (scanf("%lld %lld", &n, &r) > 0) {
		arestas.clear();
		vertices.clear();

		for (i = 0; i < n; i++) {
			scanf("%lld %lld", &x, &y);

			vertices.push_back(make_pair(x, y));

			for (j = 0; j < i; j++)
				arestas.push_back(make_pair((vertices[i].first - vertices[j].first) * (vertices[i].first - vertices[j].first)
					+ (vertices[i].second - vertices[j].second) * (vertices[i].second - vertices[j].second), make_pair(i, j)));
		}

		init(n);

		sort(arestas.begin(), arestas.end());

		i = 0;
		resp = 1;

		r2 = r * r;

		for(auto it : arestas) {
			if (unir(it.second.first, it.second.second)) {
				if (it.first < r2)
					custoA += sqrt(it.first);
				else {
					custoB += sqrt(it.first);
					resp++;
				}
			}

			i++;
		}

		printf("Case #%lld: %lld %.0lf %.0lf\n", caso++, resp, custoA, custoB);
	}

	return 0;
}
