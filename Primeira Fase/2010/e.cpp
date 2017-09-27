#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define D(x) cout << #x " = " << (x) << endl

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
	int l, c, r1, r2;
	
	while(scanf("%d %d %d %d", &l, &c, &r1, &r2), l) {
		if(2*r1 <= l && 2*r1 <= c && 2*r2 <= l && 2*r2 <= c &&
		   hypot((l-r2) - (r1), (c-r2) - r1) >= r1+r2)
		   puts("S");
		else
		   puts("N");
	}
}
