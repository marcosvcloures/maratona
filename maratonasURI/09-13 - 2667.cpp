#include <bits/stdc++.h>

using namespace std;

int main() {
	char c;
	int n, total = 0;

	while(cin >> c) {
		sscanf(&c, "%d", &n);
		total += n;
	}

	printf("%d\n", total%3);
}
