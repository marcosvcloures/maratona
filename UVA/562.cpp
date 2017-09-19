#include <bits/stdc++.h>

using namespace std;

int main() {
	set<int> valores;
	set<int>::iterator it;
	vector<int> novos_valores;
	int t, n, v, soma, i;

	scanf("%d", &t);

	while (t--) {
		valores.clear();
		valores.insert(0);
		soma = 0;

		scanf("%d", &n);

		while (n--) {
			novos_valores.clear();
			
			scanf("%d", &v);

			soma += v;
			
			for (it = valores.begin(); it != valores.end(); it++)
				novos_valores.push_back(*it + v);

			for (i = 0; i < novos_valores.size(); i++)
				valores.insert(novos_valores[i]);
		}

		printf("%d\n", min(abs(2 * (*valores.lower_bound(soma / 2)) - soma), abs(2 * (*valores.upper_bound(soma / 2)) - soma)));
	}
}