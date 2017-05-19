#include <bits/stdc++.h>

using namespace std;

int main() {
	int caminhos[10000] = { 1 }, n, v, qtd, caminho, cord_x, cord_y, a_andar;

	for (qtd = 1, v = 6; caminhos[qtd-1] <= 100000; qtd++, v += 6)
		caminhos[qtd] = caminhos[qtd - 1] + v;

	while (scanf("%d", &n) > 0 && n) {
		if (n != 1) {
			caminho = lower_bound(caminhos, caminhos + qtd, n) - caminhos;

			cord_x = caminho - 1;
			cord_y = 1;

			a_andar = n - caminhos[caminho - 1] - 1;

			while (a_andar) {
				if (cord_y == caminho && cord_x > -caminho)
					cord_x--;
				else if (cord_x == caminho && cord_y <= 0)
					cord_y++;
				else if (cord_y == -caminho)
					cord_x++;
				else if (cord_x == -caminho && cord_y > 0)
					cord_y--;
				else if (cord_y > 0)
					cord_x--, cord_y++;
				else
					cord_x++, cord_y--;

				a_andar--;
			}

			printf("%d %d\n", cord_x, cord_y);
		}
		else
			puts("0 0");
	}
}