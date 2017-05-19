#include <bits/stdc++.h>

using namespace std;

int main() {
	int t = 0, qtd, max_val, max_ini, ini_h, ini_m, fim_h, fim_m, intervalos[10000], i;
	char linha[260];

	while (scanf(" %d ", &qtd) > 0) {
		t++;

		max_val = -1;
		intervalos[0] = 600;

		for (i = 0; i < qtd; i++) {
			fgets(linha, 260, stdin);

			sscanf(linha, "%d:%d %d:%d", &ini_h, &ini_m, &fim_h, &fim_m);
		
			intervalos[i * 2 + 1] = ini_h * 60 + ini_m;
			intervalos[i * 2 + 2] = fim_h * 60 + fim_m;
		}

		intervalos[i * 2 + 1] = 1080;

		sort(intervalos, intervalos + i * 2 + 2);

		for(i = 0; i < qtd + 1; i++)
			if (intervalos[i * 2 + 1] - intervalos[i * 2] > max_val) {
				max_val = intervalos[i * 2 + 1] - intervalos[i * 2];
				max_ini = intervalos[i * 2];
			}

		if (max_val < 60)
			printf("Day #%d: the longest nap starts at %d:%02d and will last for %d minutes.\n", t, max_ini / 60, max_ini % 60, max_val);
		else
			printf("Day #%d: the longest nap starts at %d:%02d and will last for %d hours and %d minutes.\n", t, max_ini / 60, max_ini % 60, max_val / 60, max_val % 60);
	}
}