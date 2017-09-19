#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, somaTotal, somaStopped, melhor;
	char entrada[4], mapa[255] = { 0 };

	mapa[0] = 'S';
	mapa[1] = 'H';
	mapa[2] = 'D';
	mapa[3] = 'C';

	mapa['S'] = 0;
	mapa['H'] = 1;
	mapa['D'] = 2;
	mapa['C'] = 3;

	mapa['A'] = 4;
	mapa['K'] = 3;
	mapa['Q'] = 2;
	mapa['J'] = 1;

	while (scanf(" %s", entrada) > 0) {
		multiset<int> naipes[4];
		vector<int> somas(4, 0);
		vector<bool> stopped(4, 0);

		naipes[mapa[entrada[1]]].insert(entrada[0]);
		somas[mapa[entrada[1]]] += mapa[entrada[0]];

		for (i = 0; i < 12; i++)
			scanf(" %s", entrada),
			naipes[mapa[entrada[1]]].insert(entrada[0]),
			somas[mapa[entrada[1]]] += mapa[entrada[0]];

		for (i = 0; i < 4; i++) {
			if (naipes[i].count('A'))
				stopped[i] = true;

			if (naipes[i].count('K') && naipes[i].size() == 1)
				somas[i]--;
			else if (naipes[i].count('K'))
				stopped[i] = true;

			if (naipes[i].count('Q') && naipes[i].size() <= 2)
				somas[i]--;
			else if (naipes[i].count('Q') && naipes[i].size() >= 2)
				stopped[i] = true;

			if (naipes[i].count('J') && naipes[i].size() <= 3)
				somas[i]--;
		}

		somaTotal = somaStopped = 0;

		for (auto e : somas)
			somaTotal += e;

		for (auto e : stopped)
			somaStopped += e;

		if (somaTotal >= 16 && somaStopped == 4)
			puts("BID NO-TRUMP");
		else {
			for (i = melhor = 0; i < 4; i++) {
				if (naipes[i].size() == 2)
					somaTotal++, somas[i]++;
				else if (naipes[i].size() <= 1)
					somaTotal += 2, somas[i] += 2;

				melhor = max(melhor, (int) naipes[i].size());
			}

			if (somaTotal < 14)
				puts("PASS");
			else
				for(i = 0; i < 4; i++)
					if (naipes[i].size() == melhor) {
						printf("BID %c\n", mapa[i]);
						break;
					}
		}
	}
}