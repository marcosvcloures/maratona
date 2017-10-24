#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 6000000
 
typedef struct tDado {
    int h, e, r;
     
    tDado operator++(int a) {
        int aux = e;
        e = h;
        h = r;
        r = aux;
    }
    tDado operator+(const tDado &a) {
        tDado b;
        b.h = h + a.h;
        b.e = e + a.e;
        b.r = r + a.r;
        return b;
    }
    tDado operator=(const tDado &a) {
        h = a.h;
        e = a.e;
        r = a.r;
        return *this;
    }
    tDado operator=(int a) {
        h = a == 0;
        e = a == 1;
        r = a == 2;
        return *this;
    }
} tDado;
 
tDado init[MAX], tree[MAX];
int lazy[MAX];
 
void build_tree(int node, int a, int b) {
    if(a > b) 
        return;
      
    if(a == b) {
        tree[node] = init[a];
		lazy[node] = 0;
        return;
    }
      
    build_tree(node*2, a, (a+b)/2);
    build_tree(node*2+1, 1+(a+b)/2, b);
 
    tree[node] = tree[node*2] + tree[node*2+1];
	lazy[node] = 0;
}
 
void update_tree(int node, int a, int b, int i, int j, int value) {
    if(lazy[node] != 0) {
		for(int k = 0; k < lazy[node] % 3; k++)
			tree[node]++;
		
		if(a != b) {
			lazy[node*2] += lazy[node];
    		lazy[node*2+1] += lazy[node];
		}
		
		lazy[node] = 0;
	}
	
	if(a > b || a > j || b < i)
        return;
    
	if(a >= i && b <= j) {
		tree[node]++;
		
		if(a != b) {
			lazy[node*2]++;
			lazy[node*2+1]++;
		}
		
		return;
	}
	
    if(a == b) {
        tree[node]++;
        return;
    }
  
    update_tree(node*2, a, (a+b)/2, i, j, value);
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);
 
    tree[node] = tree[node*2] + tree[node*2+1];
}
 
tDado query_tree(int node, int a, int b, int i, int j) {
      
    if(a > b || a > j || b < i) { 
        tDado a;
         
        a = -1;
         
        return a;
    }
	
	if(lazy[node] != 0) {
		for(int k = 0; k < lazy[node] % 3; k++)
			tree[node]++;
		
		if(a != b) {
			lazy[node*2] += lazy[node];
    		lazy[node*2+1] += lazy[node];
		}
		
		lazy[node] = 0;
	}
  
    if(a >= i && b <= j)
        return tree[node];
  
    tDado q1 = query_tree(node*2, a, (a+b)/2, i, j);
    tDado q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);
      
    return q1 + q2;
}
 
int main () {
    char op;
    int n, m, i, a, b;
    tDado resp;
     
    while(scanf("%d %d", &n, &m) > 0) {
        for(i = 0; i < n; i++)
            init[i] = 0;
         
        build_tree(1, 0, n-1);
         
        for(i = 0; i < m; i++) {
            scanf(" %c %d %d", &op, &a, &b);
             
            if(op == 'M')
                update_tree(1, 0, n-1, a-1, b-1, 0);
            else {
                resp = query_tree(1, 0, n-1, a-1, b-1);
                 
                printf("%d %d %d\n", resp.h, resp.e, resp.r);
            }
        }
         
        printf("\n");
    }
     
    return 0;
}