#include <stdio.h>
#include <math.h>

long long int v(long long int n) {
	return (n * (n - 1)) / 2;
}

int main() {
	long long int t, n, q, max, atual;
	double x, f;
	
	scanf("%lld", &t);
	
	while(t--) {
		scanf("%lld %lld", &n, &q);
		
		max = (n*(n+1))/2;
		
		if(q > max) {
			puts("IMPOSSIVEL");
			continue;
		}
		
		atual = 20;
		
		x = 0;
		f = (x*n-(x*x-x)/2-q)/(n+x-1/2);
		
		while(atual--) {
			x = x - f;
			f = (x*n-(x*x-x)/2-q)/(n+x-1/2);
		}
		
		atual = x;
		
		while((atual*n-(atual*(atual-1))/2-q) < 0)
			atual++;
		
		printf("%lld\n", atual);
	}
}