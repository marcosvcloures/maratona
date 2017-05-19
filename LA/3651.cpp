#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, c, k, nums[101], mini, f;

	while (scanf("%d %d %d", &n, &c, &k) && n && c && k) {
		n *= c;
		memset(nums, 0, ++k * sizeof(int));
		mini = 1 << 30;

		while (n--)
			scanf("%d", &c), nums[c]++;

		for (c = 1; c < k; c++)
			mini = min(mini, nums[c]);

		for (c = f = 1; c < k; c++)
			if (nums[c] == mini)
				printf("%s%d", f == 1 ? "" : " ", c), f = 0;

		printf("\n");
	}
}