#include <stdio.h>
#include <math.h>

int main() {	
	long long int a, b, sqrta, sqrtb, qtd;
	
	scanf("%lld %lld", &a, &b);
	
	while(a || b) {
		sqrta = sqrt(a);
		sqrtb = sqrt(b);
		
		while(sqrta * sqrta < a) 
			sqrta++;
		while(sqrtb * sqrtb > b)
			sqrtb--;
			
		qtd = b - a + 1 - (sqrtb - sqrta + 1);
		
		printf("%lld\n", qtd);
		
		scanf("%lld %lld", &a, &b);
	}
}