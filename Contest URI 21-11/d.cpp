#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, i, j, min = -1, e, pode;
	
	scanf("%d %d", &n, &m);
	
	for(i = 0; i < n; i++) {
		pode = 1;
		
		for(j = 0; j < m; j++) {
			scanf("%d", &e);
			if(e != 0 && pode) {
				if(j <= min) {
					puts("N");
					return 0;
				}
				else {
					pode = 0;
					min = j;
				}
			}
		}
		
		if(pode)
			min = m;
	}
	
	puts("S");
}