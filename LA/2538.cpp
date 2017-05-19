#include <bits/stdc++.h>

using namespace std;

int main() {
	int qtd, maquinas[255], qtdUsadas, qtdEmbora, tam, val, i;
	char entrada[1000];

	while (scanf("%d", &qtd) > 0 && qtd) {
		memset(maquinas, 0, 255 * sizeof(int));
		qtdUsadas = qtdEmbora = 0;

		scanf(" %s", entrada);

		tam = strlen(entrada);

		for (i = 0; i < tam; i++) {
			val = !maquinas[entrada[i]];

			if (qtdUsadas == qtd) {
				if (maquinas[entrada[i]] == 0)
					val = 2;

				qtdEmbora += maquinas[entrada[i]] == 0;
				qtdUsadas -= maquinas[entrada[i]] == 1;
			}
			else {
				qtdUsadas += maquinas[entrada[i]] == 0;
				qtdUsadas -= maquinas[entrada[i]] == 1;
			}

			maquinas[entrada[i]] = val;
		}

		if (qtdEmbora == 0)
			puts("All customers tanned successfully.");
		else
			printf("%d customer(s) walked away.\n", qtdEmbora);
	}
}