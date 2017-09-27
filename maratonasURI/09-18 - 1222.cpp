#include <bits/stdc++.h>

using namespace std;

#define D(x) cout << #x << " = " << x << endl

int valores[10000];

int main() {
	int n, l, c;
	string s;
	int cont, nl;
	while(cin >> n >> l >> c) {
		cont = 0;
		nl = 1;
		
		while(n--) {
			cin >> s;
			
			if(cont+s.size() > c) {
				nl++;
				cont = s.size()+1;
			}
			else {
				cont += s.size()+1;
			}
		}
		
		cout << ceil((1.0*nl)/(1.0*l)) << endl;
	}
}
