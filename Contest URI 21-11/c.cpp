#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, i, desejado, resp = 0, pinos[1000];
	
	scanf("%d %d", &n, &desejado);
	
	for(i = 0; i < n; i++)
		scanf("%d", &pinos[i]);
	
	for(i = 0; i < n/2; i++) {
		pinos[i+1] += desejado - pinos[i];
		resp += abs(desejado - pinos[i]);
		pinos[n-i-2] += desejado - pinos[n-i-1];
		resp += abs(desejado - pinos[n-i-1]);
	}
	
	printf("%d\n", resp);
}