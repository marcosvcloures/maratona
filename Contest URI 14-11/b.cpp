#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, pal[200000], sum = 0, i;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
		scanf("%d", &pal[i]), sum += pal[i];
	
	sort(pal, pal + n);
	
	for(i = n-1; i >= 0, sum -= pal[i]; i--)
		if(pal[i] < sum) {
			printf("%d\n", i + 1);
			return 0;
		}
	
	puts("0");
}