#include <stdio.h>
#include <string.h>

#define GUSTAVO 1
#define LORENA 2

struct tSMS {
	int remetente, tamanho;
};

tSMS sms[4100];

int melhor(int comeco, int fim) {
	int i, economia = 0;
	
	for(i = comeco+1; i <= fim; i++) 
		if(sms[i].tamanho + sms[i-1].tamanho + 1 <= 160) {
			sms[i].tamanho += sms[i-1].tamanho + 1;
			economia++;
		}
	
	return economia;
}

int main() {
	int n, l, g, i, comeco, el, eg;
	char frase[400], p;
	
	while(scanf("%d %d %d", &n, &l, &g) > 0 && (n || l || g)) {
		eg = el = 0;
		
		for(i = 0; i < n; i++) {
			scanf(" %c", &p);
			gets(frase);
			
			sms[i].remetente = p == 'G' ? GUSTAVO : LORENA;
			
			if(sms[i].remetente == GUSTAVO)
				sms[i].tamanho = strlen(frase) - 7;
			else
				sms[i].tamanho = strlen(frase) - 6;
		}
		
		comeco = 0;
		for(i = 0; i < n; i++) {
			if(sms[i].remetente != sms[comeco].remetente) {
		//		printf("%d %d: %d\n", comeco, i-1, melhor(comeco, i-1));
				if(sms[i-1].remetente == GUSTAVO)
					eg += melhor(comeco, i-1) * g;
				else
					el += melhor(comeco, i-1) * l;
				comeco = i;
			}
		}
		
		if(sms[i-1].remetente == GUSTAVO)
			eg += melhor(comeco, i-1) * g;
		else
			el += melhor(comeco, i-1) * l;
		
		printf("%d %d\n", el, eg);
	}
}