#include <bits/stdc++.h>
using namespace std;

int pd[200] = {0};

int main(){
	int a, i, resp, primeiro = true;
	
	pd[0] = pd[1] = 1, pd[2] = 2;//, pd[3] = 5, pd[4] = 14;
	
	for(a = 3; a < 100; a++)
		for(i = 0; i < a; i++)
			pd[a] += pd[i] * pd[a-i-1];
	
	while(scanf("%d", &a) > 0) {
		printf("%s%d\n", primeiro ? "" : "\n", pd[a]);
		primeiro = false;
	}
	return 0;
}
