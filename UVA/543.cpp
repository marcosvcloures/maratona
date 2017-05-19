#include <bits/stdc++.h>
using namespace std;

char primos[1000000] = {0};

vector<int> pprimos;

int main(){
	int i, j, n, soma;

	for(i = 2; i < 1000; i++)
		if(!primos[i]){
			for(j = i * i; j < 1000000; j += i)
				primos[j] = 1;
		}

	for(i = 2; i < 1000000; i++)
		if(!primos[i])
			pprimos.push_back(i);
	
	while(scanf("%d", &n) && n) {
		for(int i = 0, j = pprimos.size() - 1; i <= j; ) {
			soma = pprimos[i] + pprimos[j];
			
			if(soma > n)
				j--;
			else if(soma < n)
				i++;
			else {
				printf("%d = %d + %d\n", n, pprimos[i], pprimos[j]);
				break;
			}
		}
	}
}
