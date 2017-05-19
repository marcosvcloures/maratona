#include <bits/stdc++.h>

using namespace std;

int main() {
	double v[50] = { 1 };
	int e;

	for (e = 1; e < 50; e++)
		v[e] = 2.0 * e / (2.0 * e + 1) * v[e - 1];

	while (scanf("%d", &e) > 0)
		printf("%.5lf\n", v[e / 2 - 1]);
}