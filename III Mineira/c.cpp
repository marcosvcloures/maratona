#include <stdio.h>
#include <queue>

using namespace std;

int matriz[1026][1026], n, t;

struct tVertice {
	int i, j;
	
	tVertice(int a, int b) {
		i = a;
		j = b;
	}
};

int flood() {
	int i, j, ai, aj, r = 0;
	queue<tVertice> fila;
	
	for(i = 1; i <= n; i++) {
		fila.push(tVertice(i, 1));
		fila.push(tVertice(1, i));
		fila.push(tVertice(i, n));
		fila.push(tVertice(n, i));
	}
	
	while(!fila.empty()) {
		if(matriz[fila.front().i][fila.front().j] >= t) 
			fila.pop();
		else {
			r++;
			ai = fila.front().i;
			aj = fila.front().j;
			
			matriz[ai][aj] = 10000;
			
			i = -1;
			j = 0;
			if(ai+i >= 1 && ai+i <= n && aj+j >= 1 && aj+j <= n && matriz[ai+i][aj+j] < t)
				fila.push(tVertice(ai+i, aj+j));
			
			i = 0;
			j = 1;
			if(ai+i >= 1 && ai+i <= n && aj+j >= 1 && aj+j <= n && matriz[ai+i][aj+j] < t)
				fila.push(tVertice(ai+i, aj+j));
			
			i = 0;
			j = -1;
			if(ai+i >= 1 && ai+i <= n && aj+j >= 1 && aj+j <= n && matriz[ai+i][aj+j] < t)
				fila.push(tVertice(ai+i, aj+j));
			
			i = 1;
			j = 0;
			if(ai+i >= 1 && ai+i <= n && aj+j >= 1 && aj+j <= n && matriz[ai+i][aj+j] < t)
				fila.push(tVertice(ai+i, aj+j));
			
			fila.pop();
		}
	}
	return r;
}

int main() {
	int i, j;
	
	scanf("%d %d", &n, &t);
	
	while(n || t) {
		for(i = 0; i <= n+1; i++)
			for(j = 0; j <= n+1; j++) 
				matriz[i][j] = 100000;
			
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++) 
				scanf("%d", &matriz[i][j]);
		
		printf("%d\n", n*n-flood());
		
		scanf("%d %d", &n, &t);
	}
}