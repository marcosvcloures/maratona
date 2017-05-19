#include <bits/stdc++.h>
using namespace std;

int main(){
	int xi, yi, xf, yf, di, df, n, p, resp, i, caso = 0, qtd[100001] = {0};
	
	
	for(i = 1; i <= 100000; i++)
		qtd[i] = qtd[i-1] + i + 1;
	scanf("%*d");
	while(scanf("%d %d %d %d", &xi, &yi, &xf, &yf) > 0) {
		caso++;
		di = xi + yi;
		df = xf + yf;
		
		if(di != df)
			resp = qtd[df - 1] - qtd[di] + 1;
		else
			resp = 0;
			
		if(di == df)
			resp -= xi;
		else
			resp += di - xi;
			
		resp += xf;
		
		printf("Case %d: %d\n", caso, resp);
	}
	return 0;
}
