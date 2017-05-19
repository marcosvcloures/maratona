#include <bits/stdc++.h>

using namespace std;

int e[2000000] = {0};
int pd[2000000] = {0};

int main() {
	int n, i;
	
	scanf("%d", &n);

	for(i = 0; i < n; i++)
		scanf("%d", &e[i]);
	
	pd[0] = e[0];
	pd[1] = max(e[1], pd[0]);
	pd[2] = max(e[2], pd[1]);
	
	for(i = 3; i < n; i++) 
		pd[i] = max(e[i] + pd[i-3], pd[i-1]);

	printf("%d\n", pd[n-1]);
}