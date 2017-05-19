#include <bits/stdc++.h>
using namespace std;

vector<int> divisores(int n)
{
	vector<int> div;
	int sqrtn = sqrt(n) + 1;

	for (int i = 1; i <= sqrtn; i++)
		if (!(n % i))
			div.push_back(i), div.push_back(n / i);

	sort(div.rbegin(), div.rend());
	return div;
}

int main()
{
	int n, nc, p, i, j;
	vector<int> candidatos;

	while (scanf("%d", &n) && n >= 0)
	{
		candidatos = divisores(n - 1);

		for (i = 0; i < candidatos.size(); i++)
		{
			nc = n;
			p = candidatos[i];

			for (j = 0; j < p; j++)
			{
				if (nc % p != 1)
					break;

				nc -= 1;

				if (nc < 0)
					break;

				nc -= nc / p;
			}

			if (j == p && p && nc % p == 0)
			{
				printf("%d coconuts, %d people and 1 monkey\n", n, p);
				goto a;
			}
		}

		printf("%d coconuts, no solution\n", n);

	a:;
	}

	return 0;
}
