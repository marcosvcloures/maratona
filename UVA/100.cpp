#include <bits/stdc++.h>

using namespace std;

#define MAX 4000000 // O valor aqui tem que ser >= 4 * tamanho do maior n
#define ELEMENTO_NEUTRO -1

int init[MAX] = {0}, tree[MAX], lazy[MAX]; 

void build_tree(int node, int a, int b) {
    if(a > b) 
        return;
     
    if(a == b) {
        tree[node] = init[a];
        return;
    }
     
    build_tree(node*2, a, (a+b)/2);
    build_tree(node*2+1, 1+(a+b)/2, b);
    
//Atualização do pai - verificar operação
    tree[node] = max(tree[node*2], tree[node*2+1]);
}

int query_tree(int node, int a, int b, int i, int j) {
    if(a > b || a > j || b < i) { 
        return ELEMENTO_NEUTRO;
    }
 
    if(a >= i && b <= j)
        return tree[node];
 
    int q1 = query_tree(node*2, a, (a+b)/2, i, j);
	
    int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);
//Retorno da arvore - verificar operação
    return max(q1, q2);
}


int main() {
	long long int i, t, c;
	
	for(i = 1; i < 1000001; i++) {
		t = i;
		c = 0;
		
		while(t != 1) {
			if(t < 1000001 && init[t]) {
				c += init[t];
				break;
			}
			else if(t % 2)
				t = 3 * t + 1;
			else
				t /= 2;
			c++;
		}
		
		init[i] = c;
	}
	
	build_tree(1, 0, 1000001);
	
	while(scanf("%lld %lld", &t, &c) > 0) 
		printf("%lld %lld %d\n", t, c, query_tree(1, 0, 1000001, min(t, c), max(t, c)) + 1);
}