#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, e, qtd;
	
	while(scanf("%d", &t) > 0) {
		qtd = 0;
		
		for(int i = 0; i < 5; i++)
			scanf("%d", &e), qtd += e == t;
			
		printf("%d\n", qtd);
	}
	
	return 0;
}
