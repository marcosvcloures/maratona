#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, e, v, c = 0;
	
	scanf("%d", &v);
	
	while(scanf("%d", &e) > 0) {
		if(e > v && !c)
			c = 1;
		if(e < v && !c)
			c = 2;
		if(e > v && c == 2 || e < v && c == 1)
			c = 3;
		
		v = e;
	}
	
	printf("%c\n", c == 1 ? 'C' : c == 2 ? 'D' : 'N');
}