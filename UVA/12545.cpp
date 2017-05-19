#include <bits/stdc++.h>

int main() {
	int n, i, len, qtd0T, qtd0S, qtdT, qtdQ, capeta = 0, r;
	char s[200], t[200];
	
	scanf("%d", &n);
	
	while(n--) {
		capeta++;
		scanf(" %s %s", s, t);
		
		qtd0S = qtd0T = qtdQ = qtdT = r = 0;
		
		for(i = 0, len = strlen(s); i < len; i++) {
			qtd0T += t[i] == '0';
			qtd0S += s[i] == '0';
		}
		
		if(qtd0T > qtd0S + qtdQ)
			printf("Case %d: -1\n", capeta);
		else {
			for(i = 0, len = strlen(s); i < len; i++) {
				qtd0T += t[i] == '0';
				qtd0S += s[i] == '0';
			}
		}	
	}
}