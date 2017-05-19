#include <bits/stdc++.h>

int main() {
	char p[46341] = { 0 };
	std::vector<int> primos;
	int e, foi, a, i, j;

	for (i = 2; i < 216; i++)
		if (!p[i])
			for (j = i * i; j < 46341; j += i)
				p[j] = 1;
	
	for(i = 2; i < 46341; i++)
		if(!p[i])
			primos.push_back(i);

	while (scanf("%d", &e) > 0 && e) {
		foi = a = 0;
		printf("%d =", e);

		if (e < 0)
			e *= -1, printf(" -1"), foi = 1;

		while (e != 1)
			if (a == primos.size())
				printf("%s%d", foi ? " x " : " ", e), e = 1;
			else if (e % primos[a] == 0)
				e /= primos[a], printf("%s%d", foi ? " x " : " ", primos[a]), foi = 1;
			else
				a++;

		printf("\n");
	}
}