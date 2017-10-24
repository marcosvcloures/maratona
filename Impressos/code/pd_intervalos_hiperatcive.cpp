#include <bits/stdc++.h>

using namespace std;

int m, n, s, f, a ,b;
vector<pair<int, int> > intervalos;	
map<pair<int, int>, int> pd;
		
int pdzona(int ii, int ini) {
	if(intervalos[ii].first == m)
		return 1;
		
	auto h = make_pair(ii, ini);
	if(pd.count(h) != 0)
		return pd[h];
	
	int cont = 0;
	for(int j=ii+1; j<n; j++) {
		if(intervalos[j].first > intervalos[ii].first && intervalos[j].second > ini && intervalos[j].second <= intervalos[ii].first) {
			cont = (cont+pdzona(j, intervalos[ii].first))%100000000;
		}
	}
	
	return pd[h] = cont;
}
		
int main() {
	while(cin >> m >> n) {
		if(m+n == 0)
			return 0;
		intervalos.clear();
		pd.clear();
		
		for(int i=0; i<n; i++) {
			cin >> a >> b;
			intervalos.push_back(make_pair(b, a));
		}
		
		sort(intervalos.begin(), intervalos.end());
		
		int cont = 0;
		for(int i=0; i<n; i++) {
			if(intervalos[i].second == 0)
				cont = (cont+pdzona(i, 0))%100000000;
		}
		
		cout << cont << endl;
	}

	return 0;
}
