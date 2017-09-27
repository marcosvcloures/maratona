#include <bits/stdc++.h>

using namespace std;

#define D(x) cout << #x << " = " << x << endl;

int main() {
	int d, vf, vg;
	double raio, tf, tg;
	
	while(scanf("%d %d %d", &d, &vf, &vg) > 0) {
		raio = sqrt(d * d + 12 * 12);
		
		tf = 12.0 / vf;
		tg = raio / vg;
		
		printf("%c\n", tg <= tf ? 'S' : 'N');
	}
}
