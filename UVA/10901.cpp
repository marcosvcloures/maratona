#include <bits/stdc++.h>

using namespace std;

int main() {
	queue<int> esq_val, esq_id, dir_val, dir_id;
	long long int tempos[20000];
	int c, n, t, m, ladoAtual, tempoAtual, val, qtdUsados, primeiro = 1, i;
	char lado[10];
	const int direita = 0, esquerda = 1;

	scanf("%d", &c);

	while (c--) {
		scanf("%d %d %d", &n, &t, &m);

		ladoAtual = esquerda;
		tempoAtual = 0;
		memset(tempos, 0, sizeof(int) * m);

		for (i = 0; i < m; i++) {
			scanf("%d %s", &val, lado);

			if (!strcmp(lado, "left"))
				esq_id.push(i), esq_val.push(val);
			else
				dir_id.push(i), dir_val.push(val);
		}

		while (!esq_val.empty() || !dir_val.empty()) {
			qtdUsados = 0;

			if (!esq_val.empty() && !dir_val.empty()) {
				if (ladoAtual == direita) {
					if (dir_val.front() > esq_val.front() && dir_val.front() > tempoAtual)
						tempoAtual = max(tempoAtual, esq_val.front()) + t, ladoAtual = esquerda;
					else
						tempoAtual = max(tempoAtual, dir_val.front());
				}
				else {
					if (dir_val.front() < esq_val.front() && esq_val.front() > tempoAtual)
						tempoAtual = max(tempoAtual, dir_val.front()) + t, ladoAtual = direita;
					else
						tempoAtual = max(tempoAtual, esq_val.front());
				}
			}
			else if (esq_val.empty()) {
				if (ladoAtual == direita)
					tempoAtual = max(tempoAtual, dir_val.front());
				else
					tempoAtual = max(tempoAtual, dir_val.front()) + t, ladoAtual = direita;
			}
			else {
				if (ladoAtual == esquerda)
					tempoAtual = max(tempoAtual, esq_val.front());
				else
					tempoAtual = max(tempoAtual, esq_val.front()) + t, ladoAtual = esquerda;
			}

			if (ladoAtual == esquerda) {
				while (!esq_val.empty() && esq_val.front() <= tempoAtual && qtdUsados < n) {
					tempos[esq_id.front()] = tempoAtual + t;
					qtdUsados++;
					esq_id.pop();
					esq_val.pop();
				}
			}
			else {
				while (!dir_val.empty() && dir_val.front() <= tempoAtual && qtdUsados < n) {
					tempos[dir_id.front()] = tempoAtual + t;
					qtdUsados++;
					dir_id.pop();
					dir_val.pop();
				}
			}

			tempoAtual += t;
			ladoAtual = !ladoAtual;
		}

		if (!primeiro)
			printf("\n");
		else
			primeiro = 0;

		for (i = 0; i < m; i++)
			printf("%lld\n", tempos[i]);
	}
}