#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c, d;
	double resp;

	while (scanf("%d %d %d %d", &a, &b, &c, &d) && a && b && c && d) {
		if (a > b)
			swap(a, b);

		if (c > d)
			swap(c, d);
	
		resp = min(((double) c) / a, ((double) d) / b);
		resp = min((double) 1, resp);
		resp = max(resp, 0.01);
		
		printf("%.0lf%%\n", floor(resp * 100));
	}
}