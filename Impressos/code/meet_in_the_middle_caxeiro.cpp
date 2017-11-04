#include <bits/stdc++.h>

using namespace std;

#define ultimo combi.size()-1
#define kultimo pos-1

long long dist_total, l;
int n;
bool visitado_combinacao[20];
long long mat_adj[20][20];
int para1, para2;

bool achei;

map<int, set<long long>[15]> puto;

int vet[20];

long long elevado(int n) {
	long long aux = 1;

	for(int i=0; i<n; i++)
		aux *= 2;

	return aux;
}

void combinacao(int val, int pos) {
    if(n-val + pos < para1)
        return;
        
	if(pos == para1) {
		int jaSei = 0;
	    for(int i=0; i<pos; i++)
	    	jaSei = jaSei | elevado(vet[i]);
	    
	    
	    do {
	        dist_total = mat_adj[0][vet[0]];
	        for(int i=1; i<pos; i++)
	            dist_total += mat_adj[vet[i]][vet[i-1]];
		    puto[jaSei][vet[pos-1]].insert(dist_total);
		} while(next_permutation(vet, vet+pos));
		
		return;
	}

	for(int i=val; i<n; i++) {
	    vet[pos] = i;
	    combinacao(i + 1, pos+1);
	}
}

void combinacao2(int val, int pos) {
    if(n-val + pos < para2)
        return;

	if(pos == para2) {
	    int jaSei = 0;
	    for(int i=1; i<n; i++) {
	    	if(!visitado_combinacao[i]) 
	        	jaSei = jaSei | elevado(i);
	    }
	    
	    do {
	        dist_total = mat_adj[0][vet[0]];
	        for(int i=1; i<pos; i++)
	            dist_total += mat_adj[vet[i]][vet[i-1]];

		    for(int it=1; it<n; it++) {
	    		if(!visitado_combinacao[it]) 
					if (puto[jaSei][it].find(l-dist_total-mat_adj[it][vet[pos-1]]) != puto[jaSei][it].end()) {
						puts("possible");
						exit(0);
					}
			}

		} while(next_permutation(vet, vet+pos));
		
		return;
	}

	for(int i=val; i<n; i++) {
	    vet[pos] = i;
	    visitado_combinacao[i] = true;
	    combinacao2(i + 1, pos+1);
	    visitado_combinacao[i] = false;
	}
}


int main() {
	 cin >> n >> l;
	    if(n%2 == 0) {
	        para1 = n/2.0-1;
		    para2 = n/2.0;
	    }
	    else {
	        para1 = n/2.0;
		    para2 = n/2.0;
	    }
	    
		achei = false;

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				scanf("%lld", &mat_adj[i][j]);

		if(n == 2) {
			if(mat_adj[0][1]*2 == l)
				puts("possible");
			else
				puts("impossible");
		}
		else {

		combinacao(1, 0);

		fill(visitado_combinacao, visitado_combinacao+n+1, false);
		visitado_combinacao[0] = true;

		vet[0] = 0;
		combinacao2(1, 0);


		if(!achei)
			puts("impossible");
		}

	return 0;
}