#include <bits/stdc++.h>

#define ll long long
#define pb push_back

#define D(x) cout << #x << " = " << x << endl;

using namespace std;

typedef vector<int> vi;

int main() {
	int n, soma, ent, pedaco, count;
	vi val;
	
	while(scanf("%d", &n) > 0) {
		val.clear();
		
		soma = count = 0;
		
		//val.pb(0);
		
		while(n--) {
			scanf("%d", &ent);
			
			soma += ent;
			
			val.pb(soma);
		}
		
		if(soma % 3 != 0) {
			puts("0");
			
			continue;
		}
		
		pedaco = soma / 3;
		
		for(auto &it : val) 
			if(binary_search(val.begin(), val.end(), (it + pedaco)) 
			   && binary_search(val.begin(), val.end(), (it + pedaco + pedaco))) 
				count++;
		
		printf("%d\n", count);
	}
}
