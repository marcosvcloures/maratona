#include <bits/stdc++.h>

using namespace std;

struct SEQ {
	vector<int> qt;
	
	SEQ() {
		qt.assign(10,0);
	}
	
	SEQ operator - (const SEQ B) {
		SEQ novo;
		for(int i=0; i<=9; i++)
			novo.qt[i] = qt[i] - B.qt[i];
		return novo;
	}
	
	SEQ operator + (const SEQ B) {
		SEQ novo;
		for(int i=0; i<=9; i++)
			novo.qt[i] = qt[i] + B.qt[i];
		return novo;
	}
	
	void operator = (const SEQ B) {
		for(int i=0; i<=9; i++)
			qt[i] = B.qt[i];
	}
};

int exp(int a) {
	int cont = 1;
	for(int i=0; i<a; i++)
		cont *= 10;
	return cont;
}

SEQ andre(int n, int tam) {
	if(tam == 0) {
		SEQ novo;
		novo.qt[0]++;
		return novo;
	}
	
	int pot = exp(tam-1);
	int pri = n/pot;
	int rest = n%pot;
	SEQ cont;
	
	cont.qt[pri] = rest+1;

	for(int i=pri-1; i>=0; i--)
		cont.qt[i] += pot;

	for(int i=0; i<=9; i++)
		cont.qt[i] += pri*(tam-1)*(pot/10);


	cont.qt[0] -= pot;

	return cont + andre(rest, tam-1);
}

int main() {
	int a, b, aux_a, aux_b;
	int qt_a, qt_b;
	
	while((scanf("%d%d", &a, &b) && a+b)) {
		aux_a = a-1;
		aux_b = b;
		
		qt_a = qt_b = 0;
		
		while(aux_a) {
			qt_a++;
			aux_a /= 10;
		}
		
		while(aux_b) {
			qt_b++;
			aux_b /= 10;
		}
	
		SEQ novo = andre(b, qt_b) - andre(a-1, qt_a);		
		cout << novo.qt[0];
		for(int i=1; i<=9; i++)
			cout << " " << novo.qt[i];
		cout << endl;
		
	}

	return 0;
}