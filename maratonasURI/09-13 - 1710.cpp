#include <bits/stdc++.h>

using namespace std;

struct plano {
	int a, b, c, d;
};

int main() {
	int n, m, x, y, z, resp = 0;
	map<vector<int>, int> mapa;
	
	scanf("%d %d", &n, &m);
	
	vector<plano> planos(n);
	
	for(auto &it : planos)
		scanf("%d %d %d %d", &it.a, &it.b, &it.c, &it.d);
		
	while(m--) {
		scanf("%d %d %d", &x, &y, &z);
		
		vector<int> val(n);
		
		for(int i = 0; i < n; i++)
			val[i] = x * planos[i].a + y * planos[i].b + z * planos[i].c > planos[i].d;
			
		if(mapa.count(val))
			mapa[val]++;
		else
			mapa[val] = 1;
	}
	
	for(auto &it : mapa)
		resp = max(resp, it.second);
		
	printf("%d\n", resp);
}
