#include <bits/stdc++.h>

using namespace std;

bool palindromo(char *s) {
	int i = 0, j = strlen(s) - 1;

	while (i < j && s[i] == s[j])
		i++, j--;

	return i >= j;
}

int main() {
	int n;
	long long int v, r, it;
	char t[20];

	scanf("%d", &n);

	while (n--) {
		scanf("%lld", &v);
		sprintf(t, "%lld", v);
		it = 0;

		while (!palindromo(t)) {
			reverse(t, t + strlen(t));
			sscanf(t, "%lld", &r);
			v += r;
			it++;
			sprintf(t, "%lld", v);
		}

		printf("%d %lld\n", it, v);
	}
}