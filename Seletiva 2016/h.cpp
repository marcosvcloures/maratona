#include <stdio.h>

int main() {
	int i, n, val[1000], count = 0, napagadas = 0, marcada = 0;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++) {
		scanf("%d", &val[i]);
		
		if(!val[i])
			napagadas++;
	}
	
	if(napagadas % 2) {
		puts("-1");
		return 0;
	}
	
	for(i = 0; i < n; i++) {
		if(!marcada && !val[i])
			marcada = 1;
		else if(marcada && !val[i]) {
			marcada = 0;
			count++;
		}
		else if(marcada) 
			count++;
	}
	
	printf("%d\n", count);
}