#include <bits/stdc++.h>

using namespace std;

int main() {
	int v[] = { 1, 2, 3, 4, 5, 0, 6, 7, 8, 9 }, e, n, d, p, c = 0;
	vector<pair<int, int> > hehe[200];

	do {
		n = (((((v[0] * 10) + v[1]) * 10) + v[2]) * 10 + v[3]) * 10 + v[4];
		d = (((((v[5] * 10) + v[6]) * 10) + v[7]) * 10 + v[8]) * 10 + v[9];

		if (n % d == 0)
			hehe[n / d].push_back(make_pair(n, d));
	} while (next_permutation(v, v + 10));

	while (scanf("%d", &e) && e) {
		p = 0;

		if (c)
			printf("\n");
		else
			c = 1;

		if (hehe[e].size() == 0)
			printf("There are no solutions for %d.\n", e);
		else {
			for (int i = 0; i < hehe[e].size(); i++)
				printf("%d / %05d = %d\n", hehe[e][i].first, hehe[e][i].second, e);
		}
	}
}