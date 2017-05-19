#include <bits/stdc++.h>
using namespace std;

string s;
int tam;

void printV(char * p){
	if(p){
		cout << p << endl;
	}
}

void permut(int index, char * pal, int oc){
	if(index == tam){
		printV(pal);
		return;
	}
	char * p = new char[tam];
	p[0] = s[index];
	for(int i = 0; i < oc; i++){
		p[i + 1] = pal[i];
	}
	oc++;
	permut(index + 1, p, oc);
	for(int i = 1; i < oc; i++){
		swap(p[i], p[i - 1]);
		permut(index + 1, p, oc);
	}

	delete [] p;
}

int main(){
	bool foi = false;

	while(cin >> s){
		if(foi)
		cout << endl;
		else foi = true;
		tam = s.size();
		char * p = new char[tam];
		permut(0, p, 0);
		delete [] p;
	}
	return 0;
}
