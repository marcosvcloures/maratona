#include <bits/stdc++.h>

int main() {
	int i;

	while(scanf("%d", &i) && i)
			printf("%d\n", __builtin_popcount(i) == 1 ? i : (i & (1 << (31 - __builtin_clz(i))) - 1) << 1);
}