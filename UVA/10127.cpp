#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, r, v, i;
	
	while (scanf("%d", &n) > 0) {
		r = v = 0;
		
		do {
			for (i = 1; (r + n * i) % 10 != 1; i++);

			r += n * i;
			
			for (; r % 10 == 1; r /= 10, v++);
		} while (r);
		
		printf("%d\n", v);		
	}
}