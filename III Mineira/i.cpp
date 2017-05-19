#include <stdio.h>

int n;

int corte(int pos) {
	if(pos <= n/2)
		return pos*2;
	else
		return (pos-n/2-1)*2 + 1;
}

int main() {
	int pos, t;
	
	while(scanf("%d %d %d", &n, &pos, &t) > 0 && (n || pos || t)) {
		while(t--) 
			pos = corte(pos);
		
		printf("%d\n", pos);
	}
}