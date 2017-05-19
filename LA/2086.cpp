#include <bits/stdc++.h>

#define numero false
#define palavra true

using namespace std;

string lower(char *pal) {
	string resp;

	while (*pal != 0)
		resp += tolower(*pal), pal++;

	return resp;
}

int main() {
	multimap<string, string> palavras;
	multiset<int> numeros;
	queue<bool> ordem;
	int num, tam, acabou, primeiro;
	char atual[100];

	multiset<int>::iterator set_it;
	multimap<string, string>::iterator map_it;

	while (scanf(" %s", atual) > 0 && atual[0] != '.') {
		palavras.clear();
		numeros.clear();		
		acabou = false;

		do {
			tam = strlen(atual) - 1;
			
			if (atual[tam] == '.')
				acabou = true;
			
			atual[tam] = 0;

			if (atual[0] >= '0' && atual[0] <= '9' || atual[0] == '-' || atual[0] == '+') {
				ordem.push(numero);
				numeros.insert(atoi(atual));
			}
			else {
				ordem.push(palavra);
				palavras.insert(make_pair(lower(atual), atual));
			}
		} while (!acabou && scanf(" %s", atual));

		set_it = numeros.begin();
		map_it = palavras.begin();
		primeiro = true;

		while (!ordem.empty()) {
			if (!primeiro)
				printf(" ");
			else
				primeiro = false;

			if (ordem.front() == numero)
				printf("%d", *set_it), set_it++;
			else
				printf("%s", (*map_it).second.c_str()), map_it++;

			if (ordem.size() == 1)
				printf(".\n");
			else
				printf(",");

			ordem.pop();
		}
	}
}