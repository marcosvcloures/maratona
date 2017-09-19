#include <bits/stdc++.h>

using namespace std;

char char2bit[255] = { 0 };

int moveLinha(int estadoAtual, int linha) {
	linha *= 8;

	int linhaRemovida = (estadoAtual & (255 << linha)) >> linha;
	
	estadoAtual = estadoAtual ^ (linhaRemovida << linha);

	linhaRemovida = ((linhaRemovida << 2) | (linhaRemovida >> 6)) & 255;

	return estadoAtual | (linhaRemovida << linha);
}

int moveColuna(int estadoAtual, int coluna) {
	coluna *= 2;

	int colunaRemovida = (estadoAtual & (3 << coluna)) >> coluna;
	estadoAtual = estadoAtual ^ (colunaRemovida << coluna);

	int colunas = estadoAtual & (50529024 << coluna);
	estadoAtual = estadoAtual ^ colunas;

	colunas >>= 8;

	return estadoAtual | (colunaRemovida << (24 + coluna)) | colunas;
}

int moveLinhaR(int estadoAtual, int linha) {
	return moveLinha(moveLinha(moveLinha(estadoAtual, linha), linha), linha);
}

int moveColunaR(int estadoAtual, int coluna) {
	return moveColuna(moveColuna(moveColuna(estadoAtual, coluna), coluna), coluna);
}

int main() {
	int estadoAtual, count;
	char e;
	map<int, int> estadosDir, estadosEsq;
	queue<int> atuais, proximos;

	char2bit['R'] = 0;
	char2bit['G'] = 1;
	char2bit['B'] = 2;
	char2bit['Y'] = 3;

	count = 0;

	proximos.push(5614335);

	while (count < 7) {
		swap(atuais, proximos);

		while (!atuais.empty()) {
			estadoAtual = atuais.front();
			atuais.pop();

			if (estadosDir.count(estadoAtual) > 0)
				continue;

			estadosDir[estadoAtual] = count;

			proximos.push(moveLinha(estadoAtual, 0));
			proximos.push(moveLinha(estadoAtual, 1));
			proximos.push(moveLinha(estadoAtual, 2));
			proximos.push(moveLinha(estadoAtual, 3));
			proximos.push(moveColuna(estadoAtual, 0));
			proximos.push(moveColuna(estadoAtual, 1));
			proximos.push(moveColuna(estadoAtual, 2));
			proximos.push(moveColuna(estadoAtual, 3));
			proximos.push(moveLinhaR(estadoAtual, 0));
			proximos.push(moveLinhaR(estadoAtual, 1));
			proximos.push(moveLinhaR(estadoAtual, 2));
			proximos.push(moveLinhaR(estadoAtual, 3));
			proximos.push(moveColunaR(estadoAtual, 0));
			proximos.push(moveColunaR(estadoAtual, 1));
			proximos.push(moveColunaR(estadoAtual, 2));
			proximos.push(moveColunaR(estadoAtual, 3));
		}

		count++;
	}

	while (scanf(" %c", &e) > 0) {
		estadoAtual = char2bit[e];
		
		for (int i = 0; i < 15; i++) {
			scanf(" %c", &e);
			estadoAtual <<= 2;
			estadoAtual |= char2bit[e];
		}
		
		if (estadosDir.count(estadoAtual)) {
			printf("%d\n", estadosDir[estadoAtual]);
			goto acabou;
		}
		else {
			estadosEsq.clear();

			while (!proximos.empty())
				proximos.pop();
			while (!atuais.empty())
				atuais.pop();

			proximos.push(estadoAtual);

			count = 0;

			while (count < 6) {
				swap(atuais, proximos);

				while (!atuais.empty()) {
					estadoAtual = atuais.front();
					atuais.pop();

					if (estadosDir.count(estadoAtual) > 0) {
						printf("%d\n", count + estadosDir[estadoAtual]);
						goto acabou;
					}

					if (estadosEsq.count(estadoAtual) > 0)
						continue;

					estadosEsq[estadoAtual] = count;

					if (count == 1) {
						printf("%lld\n", estadoAtual);
					}

					proximos.push(moveLinha(estadoAtual, 0));
					proximos.push(moveLinha(estadoAtual, 1));
					proximos.push(moveLinha(estadoAtual, 2));
					proximos.push(moveLinha(estadoAtual, 3));
					proximos.push(moveColuna(estadoAtual, 0));
					proximos.push(moveColuna(estadoAtual, 1));
					proximos.push(moveColuna(estadoAtual, 2));
					proximos.push(moveColuna(estadoAtual, 3));
					proximos.push(moveLinhaR(estadoAtual, 0));
					proximos.push(moveLinhaR(estadoAtual, 1));
					proximos.push(moveLinhaR(estadoAtual, 2));
					proximos.push(moveLinhaR(estadoAtual, 3));
					proximos.push(moveColunaR(estadoAtual, 0));
					proximos.push(moveColunaR(estadoAtual, 1));
					proximos.push(moveColunaR(estadoAtual, 2));
					proximos.push(moveColunaR(estadoAtual, 3));
				}

				count++;
			}
		}

		printf("12\n");
	acabou:;
	}
}