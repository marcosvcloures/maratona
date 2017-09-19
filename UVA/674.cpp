#include <bits/stdc++.h>

using namespace std;

int main() {
	int pd[7490], i;
	vector<int> v = { 5, 10, 25, 50 };

	fill(pd, pd + 7490, 1);

	for (auto inc : v)
		for (i = inc; i < 7490; i++)
			pd[i] += pd[i - inc];

	while (scanf("%d", &i) > 0)
		printf("%d\n", pd[i]);
}