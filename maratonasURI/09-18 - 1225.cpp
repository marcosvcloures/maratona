#include <bits/stdc++.h>

using namespace std;

#define D(x) cout << #x << " = " << x << endl

int valores[10000];

int main() {
	int n, sum, med;
	
	while(scanf("%d", &n) > 0) {
		sum = med = 0;
		
		for(int i = 0; i < n; i++)
			scanf("%d", &valores[i]), sum += valores[i];
		
		if(sum % n == 0) {
			sum /= n;
			
			for(int i = 0; i < n; i++)
				med += abs(valores[i] - sum);
				
			printf("%d\n", med / 2 + 1);
		}
		else
			puts("-1");
	}
}
