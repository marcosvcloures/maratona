#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	long long int a, b, t = 0;
	
	scanf("%lld %lld", &a, &b);
	
	if(b > a)
		swap(a, b);
	
	while(a > b) {
		a -= b+1;
		t += b+1;
		
		if(b > a)
			swap(a, b);
	}
	
	printf("%lld\n", t);
}