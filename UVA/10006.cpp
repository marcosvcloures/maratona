#include <bits/stdc++.h>

using namespace std;

std::vector<int> primos;

bool carmichael(int e) {
	int i, c;

	for (i = 0, c = 0; i < primos.size(); i++) 
		if (e == primos[i])
			return false;
		else if (e % primos[i] == 0 && (e - 1) % (primos[i] - 1))
			return false;
		else if (e % primos[i] == 0 && (e - 1) % (primos[i] - 1) == 0) {
			if (e % (primos[i] * primos[i]) == 0)
				return false;
			c++;
		}

	return c > 2;
}

int main() {
	char p[255] = { 0 };
	int e, i, j;
	
	for (i = 2; i < 16; i++)
		if (!p[i])
			for (j = i * i; j < 255; j += i)
				p[j] = 1;

	for (i = 2; i < 255; i++)
		if (!p[i])
			primos.push_back(i);
	
	while (scanf("%d", &e) && e) {
		if(carmichael(e))
			printf("The number %d is a Carmichael number.\n", e);
		else
			printf("%d is normal.\n", e);
	}
}