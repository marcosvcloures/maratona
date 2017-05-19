#include <bits/stdc++.h>

using namespace std;

long long _pow(long long a, long long b) {
	long long t = 1;

	while (b--)
		t *= a;

	return t;
}

int main() {
	char p[65536] = { 0 };
	vector<long long> primos;
	map<long long, long long> fatores_m;
	map<long long, long long>::iterator it;

	long long e, n, m, a, i, j, t;

	for (i = 2; i < 257; i++)
		if (!p[i])
			for (j = i * i; j < 65536; j += i)
				p[j] = 1;

	for (i = 2; i < 65536; i++)
		if (!p[i])
			primos.push_back(i);

	while (scanf("%lld %lld", &n, &m) > 0) {
		a = 0;
		fatores_m.clear();

		if (m == 0) {
			printf("%lld does not divide %lld!\n", m, n);
			goto proxima;
		}
		if (n == 0) {
			printf("%lld divides %lld!\n", m, n);
			goto proxima;
		}

		t = m;

		while (t != 1)
			if (a == primos.size()) {
				fatores_m[t] = 1;

				break;
			}
			else if (t % primos[a] == 0) {
				fatores_m[t] = 0;
	
				while(t % primos[a] == 0)
					t /= primos[a], fatores_m[primos[a]]++;
			}
			else
				a++;

		for (it = fatores_m.begin(); it != fatores_m.end(); it++) {
		//	printf("f: %lld, s: %lld, m: %lld\n", (*it).first, (*it).second, (*it).first * (*it).second);
			printf("p: %lld\n", _pow(n / (*it).first, (*it).second / (*it).first));
			if (_pow(n / (*it).first, (*it).second / (*it).first) < (*it).second) {
				printf("%lld does not divide %lld!\n", m, n);
				goto proxima;
			}
		}

		printf("%lld divides %lld!\n", m, n);

	proxima:;
	}
}