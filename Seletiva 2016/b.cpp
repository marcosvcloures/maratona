#include <stdio.h>
#include <algorithm>

using namespace std;

struct l {
	int qtd;
	char letra;
	
	bool operator<(l a) const {
		if(qtd == a.qtd)
			return letra < a.letra;
		return qtd > a.qtd;
	}
};

int main() {
	char n = 0;
	l letras[26];
	
	for(n = 0; n < 26; n++) {
		letras[n].qtd = 0;
		letras[n].letra = 'A'+n;
	}
	
	while(scanf(" %c", &n) > 0) 
		letras[n-'A'].qtd++;
	
	sort(letras, letras+26);
	
	for(n = 0; n < 26; n++)
		printf("%c %d\n", letras[n].letra, letras[n].qtd);
}