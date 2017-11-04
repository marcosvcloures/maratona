// Resolve:
// - De quantas maneiras conseguimos atingir Y com X tentativas
// - Dado X tentativas, conseguimos atingir Y?
// Complexidade:
// X * Ymax * Ymax(log Ymax)

// TEOREMA DA CONVOLUÇÃO:
// Podemos fazer a convolução de 2 polinomios utilizando a FFT
// Reduzindo a complexidade de n^2 para n log n
// Definimos a convolução como h[i] = sum(a[j] * b[j-i]) para todo j de 0 a i.
// Exemplo: h[5] = a[5] * b[0] + a[4] * b[1] + a[3] * b[2]...
// Segundo o teorema da convolução
// h(f . g) = transformada inversa de (transformada (f) * transformada (g))
// onde . é o operador de convolução.
// e * é o operador de multiplicação termo a termo.

#include <bits/stdc++.h>

using namespace std;

// primeira potência de 2 maior que o limite de H
const int MAX_DIST = 1 << 19;

typedef complex<double> cpx;
const double pi = acos(-1.0);

int maxDist;

void fft(vector<cpx> &a, bool invert)
{
    int n = (int)a.size();

    for (int i = 1, j = 0; i < n; ++i)
    {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1)
    {
        double ang = 2 * pi / len * (invert ? -1 : 1);
        cpx wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len)
        {
            cpx w(1);
            for (int j = 0; j < len / 2; ++j)
            {
                cpx u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert)
        for (int i = 0; i < n; ++i)
            a[i] /= n;
}

// Exemplo:
// Há um robo que pode disparar bolas em N distâncias diferentes.
// Queremos saber se ele alcança uma distância M com 1 ou 2 tacadas.
// Resolução:
// Podemos definir um vetor distances[MAX_DIST],
// onde a distances[i] = 1 se ele pode tacar até a distancia i
// e distances[i] = 0 caso contrario
// Para ver se o robo acerta com 1 tacada, é trivial.
// Para ver se o robo acerta com 2 tacadas, podemos fazer a convolução de distances com distances.
// Ex: Acertar a Pode[10] é igual a: Pode[10] || Pode[9] * Pode[1] || Pode[8] * Pode[2]...
// Ou seja, H = FFTi(FFT(distances) ** 2);

// Complexidade:
// 2 * 200k * log(200k) = 8m

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, d;
    vector<cpx> distances;

    while (cin >> N)
    {
        maxDist = 0;

        distances = vector<cpx>(MAX_DIST);

        // Distancia 0 é uma posição de "possível"
        distances[0] = cpx(1, 0);

        for (int i = 0; i < N; i++)
        {
            cin >> d;
            if (d > maxDist)
                maxDist = d;
            distances[d] = cpx(1, 0);
        }

        int shiftAmount;

        for (shiftAmount = 0; (maxDist >> shiftAmount) != 0; shiftAmount++)
            ;

        maxDist = 1 << (shiftAmount + 1);

        distances.resize(maxDist);

        fft(distances, false);

        // Multiplicação termo a termo de f e g, no caso, f = g = fftOut
        // fftOut *= fftOut
        for (int i = 0; i < maxDist; i++)
            distances[i] = distances[i] * distances[i];

        // transformada inversa da multiplcação termo a termo.
        fft(distances, true);

        cin >> N;
        int total = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> d;

            // Entra a distancia d
            // e verifica se a parte real da distância[d] é positiva
            // distância[d] guarda de quantas maneiras conseguimos atingir D
            if (distances[d].real() > 0.01)
                total++;
        }

        cout << total << endl;
    }
}