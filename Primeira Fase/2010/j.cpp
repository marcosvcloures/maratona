#include <cstdio>

int main () {
	int n, entrada, i, resp, respT;
	
	scanf("%d", &n);
	while(n != 0) {
		while(n > 0) {
			i = resp = respT = 0;
			
			while(i < 5) {
				scanf("%d", &entrada);
				
				if(entrada <= 127) {
					resp = i;
					respT++;
				}
				
				i++;
			}
			
			if(respT == 1)
				printf("%c\n", resp == 0 ? 'A' : resp == 1 ? 'B' : resp == 2 ? 'C' : resp == 3 ? 'D' : 'E');
			else
				puts("*");
			
			n--;
		}
		
		scanf("%d", &n);
	}
	
	return 0;
}
