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
    int t, n, m, i, resp = 0, atual = 0;

    scanf("%d %d %d", &t, &n, &m);

    vvi v(2, vi(m+2, 0));

    for(i = n; i <= m; i++)
        v[atual][i] = 1;

    while(--t) {
        atual = !atual;

        for(i = n; i <= m; i++)
            v[atual][i] = (v[!atual][i-1] + v[!atual][i + 1]) % 1000000007;
    }

    for(i = n; i <= m; i++)
        resp = (resp + v[atual][i]) % 1000000007;

    printf("%d\n", resp);
}