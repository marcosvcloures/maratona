#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int tam, p, raiz, anel, lim, x, y, passo;
	long long val[100001] = {0};
	
	val[0] = 1;
	for(long long int i = 1; i < 100001; i++)
		val[i] = (i*2+1) * (i*2+1);
	
	while(scanf("%lld %lld", &tam, &p) > 0 && (tam || p)) {
		anel = lower_bound(val, val+100001, p) - val + 1;
		
		x = y = anel + tam / 2;
		passo = val[anel-1] - p;
		
		x = y = lim = anel + tam / 2;
		
		anel = (anel) * 2 - 2;
		
		while(passo) {
			if(x == lim && y == lim) {
				y -= min(anel, passo);
				passo -= min(anel, passo);
			}
			else if(x == lim) {
				x -= min(anel, passo);
				passo -= min(anel, passo);
			}
			else if(y == lim){		
				
				x += min(anel, passo);
				passo -= min(anel, passo);
			}else
			{
				y += min(anel,passo);
				passo -= min(anel, passo);
			}
		}
		
		printf("Line = %lld, column = %lld.\n", y, x);
	}
	
	return 0;
}
