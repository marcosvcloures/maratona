#include <bits/stdc++.h>

using namespace std;

char v[1000000], t[1000000];

int main() {
	int i, tam, c = 0;

	while (scanf(" %s", v) && !(v[0] == '0' && v[1] == 0)) {
		c++;
		tam = strlen(v);

		t[tam] = 0;
		t[tam - 1] = v[tam - 1];
		t[tam - 2] = 0;

		for (i = tam - 2; i >= 0; i--) {
			t[i] += v[i] - t[i + 1];

			if (i)
				t[i - 1] = 0;

			if (t[i] < 0) {
				t[i] += 10;

				if (i)
					t[i - 1]--;
			}

			t[i] += '0';
		}

		if (t[0] != '0')
			printf("%d. %s\n", c, t);
		else
			printf("%d. IMPOSSIBLE\n", c);
	}
}