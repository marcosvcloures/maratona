#include <bits/stdc++.h>

using namespace std;

int main() {
	stack<char> tags;
	stack<int> pos;
	char frase[1000], expected[100] = { 0 }, found[100] = { 0 };
	int tam, i, qtdTot;

	while (gets(frase)) {
		tam = strlen(frase);

		qtdTot += tam;

		if (!expected[0]) {
			for (i = 0; i < tam - 3; i++) {
				if (frase[i] == '<') {
					if (frase[i + 1] >= 'A' && frase[i + 1] <= 'Z' && frase[i + 2] == '>')
						tags.push(frase[i + 1]), pos.push(qtdTot + i);
					else if (frase[i + 1] == '/' && frase[i + 2] >= 'A' && frase[i + 2] <= 'Z' && frase[i + 3] == '>') {
						if (tags.empty()) {
							sprintf(expected, "#");
							sprintf(found, "</%c>", frase[i + 2]);
							break;
						}
						else if (frase[i + 2] != tags.top()) {
							sprintf(expected, "</%c>", tags.top());
							sprintf(found, "</%c>", frase[i + 2]);
							break;
						}
						else
							tags.pop();
					}
				}
			}

			if (tam >= 3 && frase[i] == '<'	&& frase[i + 1] >= 'A' && frase[i + 1] <= 'Z' && frase[i + 2] == '>')
				tags.push(frase[i + 1]), pos.push(qtdTot + i);
		}

		if (qtdTot > 1 && frase[tam - 1] == '#') {
			if (expected[0] == 0 && tags.empty())
				puts("Correctly tagged paragraph");
			else if (expected[0] != 0)
				printf("Expected %s found %s\n", expected, found);
			else
				printf("Expected </%c> found #\n", tags.top());

			while (!tags.empty())
				tags.pop(), pos.pop();

			expected[0] = found[0] = qtdTot = 0;
		}
		else if (qtdTot == 1)
			break;
	}
}