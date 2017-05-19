#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, temp1[8] = {0}, temp2[8], *mod, *novo, i, e;
	long long resp = 0;
	
	mod = temp2;
	novo = temp1;
	
	scanf("%d", &n);
	
	while(n--) {
		swap(mod, novo);
		
		scanf("%d", &e);
		
		e %= 8;
		
		mod[0]++;
		
		for(i = 0; i < 8; i++) 
			novo[(i + e) % 8] = mod[i];
		
		resp += novo[0];
	}
	
	printf("%lld\n", resp);
}