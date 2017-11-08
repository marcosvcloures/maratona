#include <bits/stdc++.h>

using namespace std;

long long mdc(long long a, long long b)
{
    long long remainder;
    while (b != 0)
    {
        remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main() {

	multiset<long long> original;
	
	long long n, s, t;
	long long aux;

	cin >> n >> s >> t;

	for(long long i=0; i<n; i++) {
		scanf("%lld", &aux);
		original.insert(aux);
	}

	long long melhor = 1LL<<60, pior = -1, media = 0;
	long long t_mod;

	for(auto it = original.begin(); it != original.end(); it++) {
		multiset<long long> esteira = original;

		long long tempo = *it;

		long long diferenca;
		auto quem = esteira.erase(esteira.lower_bound(tempo));
		auto fulano = esteira.begin();
		tempo += t;

		while(!esteira.empty()) {
			t_mod = tempo%s;

			quem = esteira.lower_bound(t_mod);
			if(quem == esteira.end())
				quem = esteira.begin();

			if(*quem < t_mod)
				tempo += s + *quem - t_mod;
			else
				tempo += *quem - t_mod;

			esteira.erase(quem);
			tempo += t;
		}

		tempo -= *it;
		melhor = min(melhor, tempo);

		if(it == original.begin()) {
			auto asd = original.end();
			asd--;
			diferenca = *it + s - *asd;
		}
			else {
			fulano = it;
			fulano--;
			diferenca = *it - *fulano;
		}

		pior = max(pior, tempo + diferenca - 1);
		media += diferenca*tempo + diferenca*(diferenca-1)/2;
	}

	if(original.count(*original.begin()) == original.size()) {
		pior = melhor+s-1;
		media = s*melhor + s*(s-1)/2;
	}

	cout << melhor << "\n" << pior << endl;

	long long mmm = mdc(media, s);

	printf("%lld/%lld\n", media/mmm, s/mmm);
	return 0;
}