#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define D(x) cout << #x " = " << (x) << endl

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int mdc(int a, int b)
{
    int remainder;
    while (b != 0)
    {
        remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int mmc(int a, int b)
{
    int temp = mdc(a, b);

    return temp ? (a / temp * b) : 0;
}

vector<int> divisores(int n)
{
    vector<int> div;
    int sqrtn = sqrt(n), i;

    while(sqrtn * sqrtn < n)
        sqrtn++;

    for (i = 1; i < sqrtn; i++)
        if (!(n % i))
            div.push_back(i), div.push_back(n / i);

    if(sqrtn * sqrtn == n)
        div.push_back(sqrtn);

    return div;
}

int main() {
    int n, max, res = 1, e, desejado;

    scanf("%d %d", &n, &max);

    while(n--) {
        scanf("%d", &e);

        res = mmc(res, e);
    }

    desejado = (max / res) * res;

    vi div = divisores(desejado);

    sort(div.begin(), div.end());

    for(auto &it : div)
        if(mmc(it, res) == desejado) {
            printf("%d\n", it);
            
            return 0;
        }
}