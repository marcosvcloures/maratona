#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define D(x) cout << #x " = " << (x) << endl

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> ii;
typedef vector<ii> vii;

vi cap, visitado;
vii grafo[12000];

int k;

int caminha(int atual) {
    int r = 0;

    visitado[atual] = 1;

    for(auto &it : grafo[atual]) {
        if(!visitado[it.first]) {
            r += caminha(it.first);
            
            cap[atual] += cap[it.first];

            r += it.second * ceil(cap[it.first] * 1.0 / k) * 2;
        }
    }

    return r;
}

int main() {
    int n, i, a, b, c;

    scanf("%d %d", &n, &k);

    cap = vi(n);
    visitado = vi(n, 0);

    for(auto &it : cap)
        scanf("%d", &it);

    for(i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);

        a--;
        b--;

        grafo[a].pb(ii(b, c));
        grafo[b].pb(ii(a, c));
    }

    printf("%d\n", caminha(0));
}