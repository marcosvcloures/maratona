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
#define MAX_DIST (262144 * 2)

typedef complex<double> cpx;
const double pi = acos(-1.0);

int p[MAX_DIST];
int maxDist;

// in:     vector de entrada
// out:    vector de saida
// n:      Tamanho do input/output {DEVE SER DA ORDEM DE 2}
// type:   1 = Transformada, -1 = Transformada inversa
void FFT(vector<cpx> &v, vector<cpx> &ans, int n, int type)
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
		const cpx wn(cos(type * pi / sz), sin(type * pi / sz));
		for (o = 0; o < n; o += (sz << 1))
		{
			cpx w = 1;
			for (i = 0; i < sz; i++)
			{
				const cpx u = ans[o + i], t = w * ans[o + sz + i];
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
	int N, d;
	vector<cpx> distances, fftOut;

	while (cin >> N)
	{
		maxDist = 0;

		distances = vector<cpx>(MAX_DIST);
		fftOut = vector<cpx>(MAX_DIST);

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

		// fftOut <= transformada de distances
		FFT(distances, fftOut, maxDist, 1);

		// Multiplicação termo a termo de f e g, no caso, f = g = fftOut
		// fftOut *= fftOut
		for (int i = 0; i < maxDist; i++)
			fftOut[i] = fftOut[i] * fftOut[i];

		// transformada inversa da multiplcação termo a termo.
		FFT(fftOut, distances, maxDist, -1);

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
	return 0;
}