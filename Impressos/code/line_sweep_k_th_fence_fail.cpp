#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define D(x) //cout << #x << " = " << x << endl

typedef pair<int, int> Ponto;
typedef pair<Ponto, int> Flor;

typedef tree<
	pair<int, int>,
	null_type,
	less<pair<int, int>>,
	rb_tree_tag,
	tree_order_statistics_node_update> 
	ordered_set;

int main() {
	vector<Flor> flores;
	vector<Ponto> cercas;
	
	int p, v, aux; 
	long long resp;
	
	scanf("%d %d", &p, &v);
	
	ordered_set eventos;
	
	flores = vector<Flor>(p);
	cercas = vector<Ponto>(v);
	
	for(int i = 0; i < p; i++)
		scanf("%d %d", &flores[i].first.first, &flores[i].first.second), 
		flores[i].second = i + 1;
		
	for(auto &it : cercas)
		scanf("%d %d", &it.first, &it.second);
		
	sort(flores.begin(), flores.end());
	sort(cercas.begin(), cercas.end());
	
	auto flor = flores.begin();
	auto cerca = cercas.begin();
	
	resp = 0;
	aux = 1;
	
	while(flor != flores.end()) 
	{
		if(cerca == cercas.end()) 
		{
			resp += flor->second;
			
			++flor;
		}
		else if(flor->first < *cerca)
		{
			auto lb = eventos.lower_bound({flor->first.second, 5000000});
			auto order = eventos.order_of_key(*lb);
			
			if(lb == eventos.end() || order % 2 == 0) 
				resp += flor->second;
				
			++flor;
		}
		else 
		{
		    auto lb = eventos.lower_bound({cerca->second, 0});
		    
		    if(lb != eventos.end() && lb->first == cerca->second)
		        eventos.erase(lb);
		    else
			    eventos.insert({cerca->second, aux++});
			
			cerca++;
		}
	}
	
	printf("%lld\n", resp);
}
