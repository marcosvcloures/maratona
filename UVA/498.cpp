#include <bits/stdc++.h>

using namespace std;

int main() {
	int coef[100], e, x, resp, i, gambiarra2;

	while (scanf("%d", &coef[0]) > 0) {
		gambiarra2 = true;

		for (e = 1; scanf("%*[^-0-9\n]%d", &coef[e]); e++);

		scanf("%d", &x);

		goto gambiarra1;

		while (scanf("%*[^-0-9\n]%d", &x)) {
			gambiarra2 = false;
		gambiarra1:
			for (i = resp = 0; i < e; i++)
				resp *= x, resp += coef[i];

			printf("%s%d", gambiarra2 ? "" : " ", resp);
		}

		printf("\n");
	}
}