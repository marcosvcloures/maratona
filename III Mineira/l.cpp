#include<bits/stdc++.h>

using namespace std;

typedef pair<int, bool> pib;

vector<pib> lista[1001];
int visitado[1001] = {0};
vector<long long int> moeda;
long long int pd1[1001], pd2[1001], *pd_n, *pd_v;

int n, a, i, ini, c,x,y,sum = 0;

bool percorre(int atual, int cor, int &cont){
    if(visitado[atual] != 0 && visitado[atual] != cor) return false;
    if(visitado[atual]) return true;

    visitado[atual] = cor;
    cont += cor;
    for(int j = 0; j < lista[atual].size();j++){
        if(lista[atual][j].second){
            if(!(percorre(lista[atual][j].first,cor,cont)))
            	return false;
        }
        else{
            if(!(percorre(lista[atual][j].first,-cor,cont)))
            	return false;
        }
    }
    return true;
}

int main(){
    fora:
    
    pd_v = pd1;
    pd_n = pd2;

    while(scanf("%i %i %i", &n, &a, &ini) && n){
        sum = 0;
        memset(visitado, 0, 1001*sizeof(int));
        moeda.clear();

        for(i = 0; i < 1001; i++) lista[i].clear();

        while(a--){
            scanf("%d %d", &x, &y), lista[x].push_back(pib(y, true)), lista[y].push_back(pib(x, true));
        }

        while(ini--){
            scanf("%d %d", &x, &y), lista[x].push_back(pib(y, false)), lista[y].push_back(pib(x, false));
        }
        if(n&1) {puts("0");continue;}

        for(i = 1; i <= n; i++){
            if(!visitado[i]){
                if(!percorre(i,1,c = 0)){
                    puts("0");
                    goto fora;
                }
                else{
                    moeda.push_back(abs(c));
                    sum += abs(c);
                }
            }
        }
        
        memset(pd_n, 0, 1001*sizeof(long long));
        
		pd_n[0] = 1;
		
        for(i = 0; i < moeda.size(); i++) {
        	swap(pd_v, pd_n);
			
        	memset(pd_n, 0, 1001*sizeof(long long));
        	
			int limite = sum;
			
        	for(int j = 0; j <= limite; j++)
        		pd_n[j] = pd_v[j] + (j-moeda[i] >= 0 ? pd_v[j-moeda[i]] : 0), pd_n[j] %= 2000000014;
        }
		
        printf("%lli\n", pd_n[sum/2]/2);
    }

    return 0;
}
