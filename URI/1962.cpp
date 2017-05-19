#include <stdio.h>

int main() {
	int n, e;
	
	scanf("%d", &n);
	
	while(n--) {
		scanf("%d", &e);
		
		e -= 2015;
		
		printf("%d %s\n", e >= 0 ? e+1 : -e, e >= 0 ? "A.C." : "D.C.");
	}
}