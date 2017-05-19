#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int n, b, h, w, p, a, i, mini, pode, vagas;

	while (scanf("%d %d %d %d", &n, &b, &h, &w) > 0) {
		mini = 1 << 30;

		while (h--) {
			pode = false;

			scanf("%d", &p);

			for (i = 0; i < w; i++)
				scanf("%d", &vagas), pode = pode || vagas > n;

			if (p * n <= b && pode)
				mini = min(mini, p * n);
		}

		if (mini != 1 << 30)
			printf("%d\n", mini);
		else
			puts("stay home");
	}
}