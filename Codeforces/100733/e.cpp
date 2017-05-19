#include <bits/stdc++.h>

using namespace std;

int e[2000000];

int main() {
	int n, m, i;
	
	scanf("%d %d", &n, &m);
	
	for(i = 0; i < n; i++)
		scanf("%d", &e[i]);
	
	sort(e, e+n);
	
	printf("%d\n", e[m-1]);
}