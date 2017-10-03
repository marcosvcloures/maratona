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
const int MAX_DIST = 1 << 22 + 1;

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
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string palavra;
	int soma = 0, acc = 0;
	vector<cpx> fftEsq, fftDir, fftOut;

	cin >> palavra;

	fftEsq = vector<cpx>(MAX_DIST);
	fftDir = vector<cpx>(MAX_DIST);
	fftOut = vector<cpx>(MAX_DIST);

	for(auto &it : palavra) 
	{
		it -= 'a' - 1;
		soma += it;

		fftEsq[soma] = cpx(1, 0);
	}

	fftDir[soma] = cpx(1, 0);

	for(auto &it : palavra) {
		acc += it;

		fftDir[soma - acc] = cpx(1, 0);
	}

	int shiftAmount;

	for (shiftAmount = 0; (soma >> shiftAmount) != 0; shiftAmount++)
		;

	maxDist = 1 << (shiftAmount + 1);

	FFT(fftEsq, fftOut, maxDist, 1);
	FFT(fftDir, fftEsq, maxDist, 1);

	for (int i = 0; i < maxDist; i++)
		fftOut[i] = fftOut[i] * fftEsq[i];

	FFT(fftOut, fftEsq, maxDist, -1);

	int total = 0;

	assert(2 * soma < MAX_DIST);

	for (int i = soma + 1; i <= 2 * soma; i++)
	{
		if (fftEsq[i].real() > 0.1)
			total++;
	}

	cout << total << endl;
}