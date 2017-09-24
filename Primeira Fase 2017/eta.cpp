#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

// BEGIN COPIED CODE
#define PI M_PI
#define TWOPI (2.0*PI)

char txt[110000];

void fft(double data[], int nn, int isign)
{
    int n, mmax, m, j, istep, i;
    double wtemp, wr, wpr, wpi, wi, theta;
    double tempr, tempi;

    n = nn << 1;
    j = 1;
    for (i = 1; i < n; i += 2) {
        if (j > i) {
            tempr = data[j];     data[j] = data[i];     data[i] = tempr;
            tempr = data[j+1]; data[j+1] = data[i+1]; data[i+1] = tempr;
        }
        m = n >> 1;
        while (m >= 2 && j > m) {
            j -= m;
            m >>= 1;
        }
        j += m;
    }
    mmax = 2;
    while (n > mmax) {
        istep = 2*mmax;
        theta = TWOPI/(isign*mmax);
        wtemp = sin(0.5*theta);
        wpr = -2.0*wtemp*wtemp;
        wpi = sin(theta);
        wr = 1.0;
        wi = 0.0;
        for (m = 1; m < mmax; m += 2) {
            for (i = m; i <= n; i += istep) {
                j =i + mmax;
                tempr = wr*data[j]   - wi*data[j+1];
                tempi = wr*data[j+1] + wi*data[j];
                data[j]   = data[i]   - tempr;
                data[j+1] = data[i+1] - tempi;
                data[i] += tempr;
                data[i+1] += tempi;
            }
            wr = (wtemp = wr)*wpr - wi*wpi + wr;
            wi = wi*wpr + wtemp*wpi + wi;
        }
        mmax = istep;
    }
}
// END COPIED CODE

#define ASSERT(A,p,q) assert(p <= A && q >= A)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

typedef long long ll;

int N;
ll A[1<<23];

double X[1<<24] = {0}, Y[1<<24] = {0};

int method3() {
    int su = 0;
    FOR(i,1,N+1) su += A[i];
    X[1] = Y[2*su + 1] = 1;
    int t = 0;
    FOR(i,1,N+1) {
        t += A[i];
        X[2*t + 1] = Y[2*(su-t) + 1] = 1;
    }
    int lim = su;
    while(su&(su-1)) su &= su-1;
    su <<= 1;
    fft(X,su*2,1);
    fft(Y,su*2,1);
    FOR(i,0,su*2) {
        int p = 2*i + 1, q = 2*i + 2;
        double a = X[p]*Y[p] - X[q]*Y[q], b = X[p]*Y[q] + X[q]*Y[p];
        X[p] = a;
        X[q] = b;
    }
    fft(X,su*2,-1);
    int res = 0;
    FOR(i,lim+1,lim*2+1) {
        if(X[2*i + 1] > 0.1) res++;
    }
    return res;
}

int main() {
    N = strlen(fgets(txt, sizeof(txt), stdin)) - 1;

    long long t = N, s = 0;
    
    FOR(i,1,N+1) {
        A[i] = txt[i - 1] - 'a' + 1;

        s += A[i];
    }
    
    int res;
    res = method3();

    printf("%d\n",res);
    return 0;
}

