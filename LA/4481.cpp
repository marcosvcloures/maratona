#include <bits/stdc++.h>

using namespace std;

int main() {
	char entrada[202];
	int val[256] = { 0 }, resp, count, tam, i;

	val['W'] = 64;
	val['H'] = 32;
	val['Q'] = 16;
	val['E'] = 8;
	val['S'] = 4;
	val['T'] = 2;
	val['X'] = 1;

	while (scanf(" %s", entrada) && entrada[0] != '*') {
		tam = strlen(entrada);
		resp = 0;

		for (i = 0; i < tam; i++) {
			if (entrada[i] == '/') {
				resp += count == 64;
				count = 0;
			}
			else
				count += val[entrada[i]];
		}

		printf("%d\n", resp);
	}
}