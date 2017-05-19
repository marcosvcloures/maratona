#include <bits/stdc++.h>

int main() {
	int a, b;
	
	scanf("%d", &a);
	
	while(scanf("%d", &b) > 0) {
		if(b < a) {
			puts("NAO");
			return 0;
		}
		
		a = b;
	}
	
	puts("SIM");
}