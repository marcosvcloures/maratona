#include <bits/stdc++.h>

int main() {
	char pal[10000];
	int i;
	
	scanf(" %s", &pal);
	
	for(i = 0; i < strlen(pal); i += 2)
		printf("%c", pal[i+1]);
	
	while(scanf(" %s", &pal) > 0) {
		printf(" ");
		
		for(i = 0; i < strlen(pal); i += 2)
			printf("%c", pal[i+1]);
	}
	
	printf("\n");
}