#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, d, v;
	
	while (scanf("%d", &n) > 0) {
		d = (1 + sqrt(8 * n)) / 2;
		v = d * (d - 1) / 2;

		if(d & 1)
			printf("TERM %d IS %d/%d\n", n, d - n + v + 1, n - v);
		else
			printf("TERM %d IS %d/%d\n", n, n - v, d - n + v + 1); 
	}
}