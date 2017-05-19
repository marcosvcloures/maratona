#include <bits/stdc++.h>

using namespace std;

int main() {
	long long int a, b, r, c;

	while (scanf("%lld %lld", &a, &b) > 0 && (a || b)) {
		r = c = 0;

		while (a || b) {
			r += c = a % 10 + b % 10 + c > 9;
			a /= 10, b /= 10;
		}

		if (r)
			printf("%lld carry operation%s.\n", r, r > 1 ? "s" : "");
		else
			puts("No carry operation.");
	}
}