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
    int n, k;

    scanf("%d %d", &n, &k);

    vi v(n);

    for(auto &it : v)
        scanf("%d", &it), it = -it;
    
    sort(v.begin(), v.end());

    printf("%d\n", upper_bound(v.begin(), v.end(), v[k - 1]) - v.begin());
}