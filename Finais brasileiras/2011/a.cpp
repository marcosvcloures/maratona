#include <bits/stdc++.h>
using namespace std;

struct No {
	int esq, dir;
};

const int INF = 1<<25;

int main() {
	int s, b, i, ini, fim, resq, rdir;
	
	while(scanf("%d %d", &s, &b) && s) {
		vector<No> valores(s);
		
		valores[0].esq = INF;
		valores[0].dir = s == 1 ? INF : 1;
		
		if(s > 1) {
			valores[s-1].esq = s - 2;
			valores[s-1].dir = INF;
		}
		
		for(i = 1; i < s - 1; i++) {
			valores[i].esq = i - 1;
			valores[i].dir = i + 1;
		}
		
		while(b--) {
			scanf("%d %d", &ini, &fim);
			
			ini--;
			fim--;
			
			if(valores[ini].esq != INF) {
				resq = valores[ini].esq;
				
				if(valores[fim].dir != INF) {
					rdir = valores[fim].dir;
					
					valores[valores[ini].esq].dir = valores[fim].dir;
					valores[valores[fim].dir].esq = valores[ini].esq;
				}
				else {
					rdir = INF;
					
					valores[valores[ini].esq].dir = INF;
				}
			}
			else {
				resq = INF;
				
				if(valores[fim].dir != INF) {
					rdir = valores[fim].dir;
					
					valores[valores[fim].dir].esq = INF;
				}
				else 
					rdir = INF;
			}
			
			if(resq == INF)
				printf("* ");
			else
				printf("%d ", resq + 1);
			
			if(rdir == INF)
				printf("*\n");
			else
				printf("%d\n", rdir + 1);
		}
		puts("-");
	}
}
