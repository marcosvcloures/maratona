#include <cstdio>

int main () {
	int a, b, c;
	
	while(scanf("%d %d %d", &a, &b, &c) != EOF) 
		printf("%c\n", a == b && b == c ? '*' : a == b ? 'C' : b == c ? 'A' : 'B');
	
	return 0;
}
