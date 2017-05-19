#include <stdio.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int dist(int b, int a) {
	int n = 0;
	
	while(a / 2 + 7 > b) {
		a++;
		b++;
		n++;
	}
	
	return n;
}

int main() {
	int a, b;
	
	scanf("%d %d", &a, &b);
	
	printf("%d\n", max(dist(a, b), dist(b, a)));
}