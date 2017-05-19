#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, t, e, r;

	while (scanf("%d %d", &n, &k) > 0) {
		for (r = n, e = 0; (n + e) >= k;) {
			t = n + e;
			r += n = t / k;
			e = t % k;
		}

		printf("%d\n", r);
	}
}