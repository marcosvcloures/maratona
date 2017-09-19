#include <bits/stdc++.h>

using namespace std;

vector<int> pd;

struct tElefante {
	int w, s, id;

	tElefante(int w, int s) {
		this->w = w;
		this->s = s;
		id = pd.size() + 1;
	}

	bool operator<(const tElefante &a) const {
		return w > a.w;
	}
};

vector<tElefante> elefantes;

int main() {
	int w, s, mx, resp = 0;

	while (scanf("%d %d", &w, &s) > 0)
		elefantes.push_back(tElefante(w, s)), pd.push_back(0);
	
	sort(elefantes.begin(), elefantes.end());
	
	for (int i = 0; i < elefantes.size(); i++) {
		mx = 0;

		for (int j = i - 1; j >= 0; j--)
			if (elefantes[j].w > elefantes[i].w && elefantes[j].s < elefantes[i].s)
				mx = max(mx, pd[j]);

		pd[i] = mx + 1;

		if (pd[i] > pd[resp])
			resp = i;
	}

	printf("%d\n", pd[resp]);

	while (resp >= 0) {
		printf("%d\n", elefantes[resp].id);

		for (int i = resp - 1; i >= 0; i--)
			if (pd[i] == pd[resp] - 1 && elefantes[i].w > elefantes[resp].w && elefantes[i].s < elefantes[resp].s) {
				resp = i;
				goto nxt;
			}

		resp = -1;
	nxt:;
	}
}