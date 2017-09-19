// TEOREMA DA CONVOLU��O:
// Podemos fazer a convolu��o de 2 polinomios utilizando a FFT
// Reduzindo a complexidade de n^2 para n log n
// Definimos a convolu��o como h[i] = sum(a[j] * b[j-i]) para todo j de 0 a i.
// Segundo o teorema da convolu��o
// h(f . g) = transformada inversa de (transformada (f) * transformada (g))
// onde . � o operador de convolu��o.
// e * � o operador de multiplica��o termo a termo.

// we use the nearest upper power of 2 to 200k
#include <bits/stdc++.h>

using namespace std;

#define MAX_DIST (262144 * 2)

typedef complex<double> num;
const double pi = acos(-1.0);
int p[MAX_DIST];

const double two_pi = 4 * acos(0);

//cpx distances[MAX_DIST];
//cpx fftOut[MAX_DIST];
int maxDist;

// from Stanford's notebook: https://web.stanford.edu/~liszt90/acm/notebook.html
// in:     input array
// out:    output array
// step:   {SET TO 1} (used internally)
// size:   Tamanho do input/output {DEVE SER DA ORDEM DE 2}
// dir:    1 = Transformada, -1 = Transformada inversa
// RESULT: out[k] = \sum_{j=0}^{size - 1} in[j] * exp(dir * 2pi * i * j * k / size)
void FFT(vector<num> &v, vector<num> &ans, int n, int type)
{
    assert(!(n & (n - 1)));
    int i, sz, o;
    p[0] = 0;
    for (i = 1; i < n; i++)
        p[i] = (p[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
    for (i = 0; i < n; i++)
        ans[i] = v[p[i]];
    for (sz = 1; sz < n; sz <<= 1)
    {
        const num wn(cos(type * pi / sz), sin(type * pi / sz));
        for (o = 0; o < n; o += (sz << 1))
        {
            num w = 1;
            for (i = 0; i < sz; i++)
            {
                const num u = ans[o + i], t = w * ans[o + sz + i];
                ans[o + i] = u + t;
                ans[o + i + sz] = u - t;
                w *= wn;
            }
        }
    }
    if (type == -1)
        for (i = 0; i < n; i++)
            ans[i] /= n;
}
// Exemplo:
// H� um robo que pode disparar bolas em N dist�ncias diferentes.
// Queremos saber se ele alcan�a uma dist�ncia M com 1 ou 2 tacadas.
// Resolu��o:
// Podemos definir um vetor distances[MAX_DIST],
// onde a distances[i] = 1 se ele pode tacar at� a distancia i
// e distances[i] = 0 caso contrario
// Para ver se o robo acerta com 1 tacada, � trivial.
// Para ver se o robo acerta com 2 tacadas, podemos fazer a convolu��o de distances com distances.
// E verificar ent�o a posi��o distances[m]

int main()
{
    int N, d;
    vector<num> distances, fftOut;

    while (cin >> N)
    {
        maxDist = 0;

        distances = vector<num>(MAX_DIST);
        fftOut = vector<num>(MAX_DIST);

        distances[0] = num(1, 0); // permit one shots

        for (int i = 0; i < N; i++)
        {
            cin >> d;
            if (d > maxDist)
                maxDist = d;
            distances[d] = num(1, 0);
        }

        int shiftAmount;

        for (shiftAmount = 0; (maxDist >> shiftAmount) != 0; shiftAmount++);
        maxDist = 1 << (shiftAmount + 1);

        // fftOut <= transformada de distances
        cout << (maxDist) << endl;

        FFT(distances, fftOut, maxDist, 1);

        // Multiplica��o termo a termo de f e g, no caso, f = g = fftOut
        // fftOut *= fftOut
        for (int i = 0; i < maxDist; i++)
            fftOut[i] = fftOut[i] * fftOut[i];

        // transformada inversa da multiplca��o termo a termo.
        FFT(fftOut, distances, maxDist, -1);

        cin >> N;
        int total = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> d;

            cout << distances[d].real() << endl;

            // Entra a distancia d
            // e verifica se a parte real da dist�ncia � != 0
            if (distances[d].real() > 0.01)
                total++;
        }
        cout << total << endl;
    }
    return 0;
}