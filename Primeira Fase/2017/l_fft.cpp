// Resolve:
// - De quantas maneiras conseguimos atingir Y com X tentativas
// - Dado X tentativas, conseguimos atingir Y?
// Complexidade:
// X * Ymax * Ymax(log Ymax)

// TEOREMA DA CONVOLU��O:
// Podemos fazer a convolu��o de 2 polinomios utilizando a FFT
// Reduzindo a complexidade de n^2 para n log n
// Definimos a convolu��o como h[i] = sum(a[j] * b[j-i]) para todo j de 0 a i.
// Exemplo: h[5] = a[5] * b[0] + a[4] * b[1] + a[3] * b[2]...
// Segundo o teorema da convolu��o
// h(f . g) = transformada inversa de (transformada (f) * transformada (g))
// onde . � o operador de convolu��o.
// e * � o operador de multiplica��o termo a termo.

#include <bits/stdc++.h>

using namespace std;

// primeira pot�ncia de 2 maior que o limite de H
const int MAX_DIST = 1 << 23;

typedef complex<double> cpx;
const double pi = acos(-1.0);

char txt[100000];
int maxDist;

// in:     vector de entrada
// out:    vector de saida
// n:      Tamanho do input/output {DEVE SER DA ORDEM DE 2}
// type:   1 = Transformada, -1 = Transformada inversa
void fft (vector<cpx> &a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*pi/len * (invert ? -1 : 1);
		cpx wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			cpx w (1);
			for (int j=0; j<len/2; ++j) {
				cpx u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}

	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
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
// Ex: Acertar a Pode[10] � igual a: Pode[10] || Pode[9] * Pode[1] || Pode[8] * Pode[2]...
// Ou seja, H = FFTi(FFT(distances) ** 2);

// Complexidade:
// 2 * 200k * log(200k) = 8m

int main()
{	
	int soma = 0, acc = 0, tam = 0, c;
    vector<cpx> fftEsq(MAX_DIST), fftDir(MAX_DIST);

	while((c = getchar()) >= 'a') {
		soma += txt[tam++] = c - 96;
		fftEsq[soma] = cpx(1, 0);
	}

	fftDir[soma] = cpx(1, 0);

	for(int i = 0; i < tam; i++) {
		acc += txt[i];

		fftDir[soma - acc] = cpx(1, 0);
	}

	int shiftAmount, lim = 2 * soma;

	for (shiftAmount = 0; (lim >> shiftAmount) != 0; shiftAmount++)
		;

	maxDist = 1 << shiftAmount;

	fftEsq.resize(maxDist);
	fftDir.resize(maxDist);

	fft(fftEsq, false);
	fft(fftDir, false);

	for (int i = 0; i < maxDist; i++)
		fftEsq[i] = fftDir[i] * fftEsq[i];

	fft(fftEsq, 1);

	int total = 0;

	assert(lim < maxDist);

	for (int i = soma + 1; i <= lim; i++)
	{
		if (fftEsq[i].real() > 0.01)
			total++;
	}

	printf("%d\n", total);
}