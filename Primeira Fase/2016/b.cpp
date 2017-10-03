#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef vector<int> vi;
typedef pair<int, int> ii;

typedef tree<
	ii,
	null_type,
	less<ii>,
	rb_tree_tag,
	tree_order_statistics_node_update>
ordered_set;

vi termina, visitado, val;

int dfs(int atual) {
	if(termina[atual] != -1)
		return termina[atual];
		
	termina[atual] = atual + 1;
	
	return termina[atual] = dfs(val[atual]);
}

struct query {
	int ini, fim, bucket, id;
	
	bool operator<(const query &a) const {
		if(bucket != a.bucket)
			return bucket < a.bucket;
			
		return fim < a.fim;
	}
};

int main() {
	int n, q;
	
	scanf("%d %d", &n, &q);
	
	val = vi(n);
	
	for(auto &it : val)
		scanf("%d", &it), --it;
		
	termina = vi(n, -1);
	
	for(auto i = 0; i < n; i++)
		dfs(i);
	
	vector<query> queries(q);
	
	int sqrtn = sqrt(n) + 1, count = 0;
	
	for(auto &it : queries)
		scanf("%d %d", &it.ini, &it.fim), --it.ini, --it.fim, it.bucket = it.ini / sqrtn, it.id = count++;
		
	sort(queries.begin(), queries.end());
	
	ordered_set arvore;
	vi respostas(q);
	
	int l = 0, r = 0;
	for(auto &it : queries) {
		
		while(r > it.fim + 1) 
			arvore.erase(ii(termina[r - 1], r - 1)), r--;
		while(r <= it.fim)
			arvore.insert(ii(termina[r], r)), r++;
			
		while(l < it.ini)
			arvore.erase(ii(termina[l], l)), l++;
		while(l > it.ini)
			arvore.insert(ii(termina[l - 1], l - 1)), l--;
		
		if(arvore.begin()->first == arvore.rbegin()->first)
			respostas[it.id] = 1;
		else {
			auto mediana = arvore.find_by_order(arvore.size() / 2);


            mediana = arvore.lower_bound(ii(mediana->first, -1));
            
            mediana--;
            
			respostas[it.id] = max(mediana->first, 1);
		}
	}
	
	for(auto &it : respostas)
		printf("%d\n", it);
}
