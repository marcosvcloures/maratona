#include <bits/stdc++.h>

using namespace std;

int main () {
	int i, n, r, entrada[500], mediana, resultado1, resultado2, resultado3;
	
	scanf("%d", &n);
	
	while(n--) {
		scanf("%d", &r);
		
		for(i = 0; i < r; i++)
			scanf("%d", &entrada[i]);
		
		mediana = r/2;
		
		sort(entrada, entrada+r);
		
		resultado1 = resultado2 = resultado3 = 0;
		
		for(i = 0; i < r; i++)
			resultado1 += abs(entrada[mediana]-entrada[i]);
	
		if(mediana+1 < r)
			for(i = 0; i < r; i++)
				resultado2 += abs(entrada[mediana+1]-entrada[i]);
		else
			resultado2 = resultado1;
		
		if(mediana-1 >= 0)
			for(i = 0; i < r; i++)
				resultado3 += abs(entrada[mediana-1]-entrada[i]);
		else
			resultado3 = resultado1;
		
		printf("%d\n", resultado1 < resultado2 && resultado1 < resultado3 ? resultado1 : resultado2 > resultado3 ? resultado3 : resultado2);
	}
}