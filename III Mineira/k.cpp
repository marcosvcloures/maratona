#include<bits/stdc++.h>

using namespace std;

bool apareceu[21000000] = {0};

int main(){
    int n, x, tam, i, numeros[21000000], qtd;

	numeros[0] = 0;
	
    while(scanf("%i", &n) && n !=0){
		if(n > 21){
            foi:
            puts("S");
            while(n--) scanf("%*i");
            continue;
        }
		
		tam = 1;
		
		while(n--){
            scanf("%i", &x);
			
			qtd = tam;
			
            for(i = 0; i < qtd; i++) {
                if(apareceu[x + numeros[i]]) {
					for(i = 0; i < tam; i++)
						apareceu[numeros[i]] = 0;
					goto foi;
				}
				
				numeros[tam] = x + numeros[i];
				tam++;
				apareceu[x + numeros[i]] = 1;
            }
        }
		
		for(i = 0; i < tam; i++)
			apareceu[numeros[i]] = 0;
		
        puts("N");
    }

    return 0;
}