#include <bits/stdc++.h>

using namespace std;

int xmdc(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	int x1, y1, mdc = xmdc(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return mdc;
}

int main() {
	int a, b, x, y, mdc;

	while (scanf("%d %d", &a, &b) > 0) {
		mdc = xmdc(a, b, x, y);
		printf("%d %d %d\n", x, y, mdc);
	}
}