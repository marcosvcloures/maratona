#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, i;
	double estudantes[1000], media, rup, rdw;

	while (scanf("%d", &n) && n != 0) {
		media = rup = rdw = 0;
		memset(estudantes, 0, sizeof(double));

		for (i = 0; i < n; i++)
			scanf("%lf", &estudantes[i]), media += estudantes[i] * 100;

		media /= n;
		media = round(media) / 100.0;

		for (i = 0; i < n; i++)
			if (estudantes[i] > media)
				rup += estudantes[i] - media;
			else
				rdw += media - estudantes[i];

		printf("$%.2lf\n", rup < rdw ? rup : rdw);
	}
}