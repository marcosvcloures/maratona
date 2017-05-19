#include <bits/stdc++.h>

using namespace std;

int main() {
	string pai, filho;
	int v, r;
	multimap<string, set<string> > pais;
	
	scanf("%d %d", &v, &r);
	
	while(v--) {
		cin >> pai >> filho;
		
		if(!pais.count(filho)) {
			set<string> a;
			a.insert(pai);
			
			pais.insert(make_pair(filho, a));
		}
		else
			pais.find(filho)->second.insert(pai);
	}
	
	while(r--) {
		cin >> pai >> filho;
		
		if(pais.count(filho) && pais.find(filho)->second.count(pai)) 
			puts("Nao e a mamae");
		else
			puts("nao e o Nao e a mamae");
	}
}