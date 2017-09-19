#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

ii pd[100][65000];

#define MAIS 1
#define MENOS 2
#define DIV 3
#define MULT 4

int main(){
	int t, p, i, j, offset = 32500, valores[102], val, resp;
	
	scanf("%d", &t);
	
	while(t--) {
		fill(pd[0], pd[0] + 100 * 65000, ii(0, -1));
		
		scanf("%d", &p);
		
		for(i = 0; i < p; i++)
			scanf("%d", &valores[i]);
			
		pd[0][offset + valores[0]] = ii(MAIS, -1);
		pd[0][offset - valores[0]] = ii(MENOS, -1);
		
		for(i = 1; i < p; i++)
			for(j = 0; j < 65000; j++) 
				if(pd[i-1][j].first) {
					val = j - offset;
					
					if(val * valores[i] > -32000 && val * valores[i] < 32000)
						pd[i][val * valores[i] + offset] = ii(MULT, j);
					
					if(val + valores[i] > -32000 && val + valores[i] < 32000)
						pd[i][val + valores[i] + offset] = ii(MAIS, j);
						
					if(val - valores[i] > -32000 && val - valores[i] < 32000)
						pd[i][val - valores[i] + offset] = ii(MENOS, j);
						
					if(val % valores[i] == 0)
						pd[i][val / valores[i] + offset] = ii(DIV, j);
				}
				
		scanf("%d", &val);
		stack<char> pilha;
		resp = val;
		
		if(pd[p-1][val + offset].first) {
			int atual;
						
			val += offset;
			
			for(i = p - 1; i > 0; i--) {
				if(pd[i][val].first == MAIS)
					pilha.push('+');
				if(pd[i][val].first == MENOS)
					pilha.push('-');
				if(pd[i][val].first == MULT)
					pilha.push('*');
				if(pd[i][val].first == DIV)
					pilha.push('/');
					
				val = pd[i][val].second;
			}
			
			if(pd[i][val].first == MENOS)
				printf("-");
			printf("%d", valores[i]);
			
			for(i = 1; i < p; i++) {
				char asd = pilha.top();
				printf("%c%d", asd, valores[i]);
				pilha.pop();
			}
			
			printf("=%d\n", resp);
		}
		else
			puts("NO EXPRESSION");
	}
	
	return 0;
}
