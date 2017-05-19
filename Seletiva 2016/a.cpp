#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	double descendo[100], subindo[100];
	int nDescendo = 0, nSubindo = 0, n, a, b, aprovados = 0, max = 0, i, atual = 0;
	
	scanf("%d", &n);
	
	while(n--) {
		scanf("%d %d", &a, &b);
		
		if(a < 60 && b < 60)
			continue;
		
		if(a >= 60 && b >= 60) {
			aprovados++;
			
			continue;
		}
		
		if(a >= 60) {
			subindo[nSubindo] = (6000 - 100*b)/(a-b);
			nSubindo++;
		}
		else {
			descendo[nDescendo] = (6000 - 100*b)/(a-b);
			nDescendo++;
		}
	}
	
	sort(subindo, subindo+nSubindo);
	sort(descendo, descendo+nDescendo);
	
	aprovados += nDescendo;
	max = aprovados;
	
	for(i = 0; i < nSubindo; i++) {
		while(subindo[i] > descendo[atual] && atual < nDescendo) {
			aprovados--;
			atual++;
		}
		
		aprovados++;
		
		if(aprovados > max)
			max = aprovados;
	}

	printf("%d\n", max);
}