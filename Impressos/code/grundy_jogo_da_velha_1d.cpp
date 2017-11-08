#include <iostream>
#include <cstring>
using namespace std;

#define MAX 10000

bool ganhou(char jogo[])
{
	char *p;

	if ((p=strstr(jogo,"XX"))!=NULL)
		return true;
	if ((p=strstr(jogo,"X.X"))!=NULL)
		return true;
	return false;
}


int main()
{
	int grundyxx[MAX+1];
	int grundy_x[MAX+1];
	int grundy__[MAX+1];

	grundyxx[2] = 0;
	grundyxx[3] = 0;
	grundyxx[4] = 0;

	for(int i=5;i<=MAX;i++) {
		bool s[MAX+1]={false};
		for(int j=2;j<=(i-1)/2;j++)
			s[grundyxx[j] ^ grundyxx[i-j-1]]=true;
		for(int j=0;j<i;j++)
			if (!s[j]) {
				grundyxx[i] = j;
				break;
			}
	}

	grundy_x[1] = 0;
	grundy_x[2] = 0;
	grundy_x[3] = 1;
	for(int i=4;i<=MAX;i++) {
		bool s[MAX+1]={false};
		s[grundyxx[i-1]]=true;
		for(int j=2;j<=i-3;j++)
			s[grundyxx[j] ^ grundy_x[i-j-1]]=true;
		for(int j=0;j<i;j++)
			if (!s[j]) {
				grundy_x[i] = j;
				break;
			}
	}

	grundy__[3] = 1;
	for(int i=4;i<=MAX;i++) {
		if (grundy_x[i-1]==0)	//Jogar X-
			grundy__[i] = 1;
		else {
			grundy__[i] = 0;
			for(int j=1;j<=(i-1)/2;j++)
				if ((grundy_x[j] ^ grundy_x[i-j-1]) == 0) {	//Jogar (-)X(-)
//cout << i << " " << j << "(" << grundy_x[j] << " " << grundy_x[i-j-1] << ")" << endl;
					grundy__[i] = 1;
					break;
				}
		}
	}


//	cout << "Done!" << endl;


	int n, g = 0;
	char jogo[MAX+1];
	int i, j;

	cin >> n;
	while(n) {
		cin >> jogo;

		if (ganhou(jogo)) {
			cout << 'S' << endl;
			cin >> n;
			continue;
		}

		for(i=0;jogo[i]!='\0';i++)
			if(jogo[i]=='X')
				break;
		if (jogo[i]=='\0') {	//sem X
			g = grundy__[i];
//			cout << "--  " << i << " g=" << grundy__[i] << endl;
		}
		else {
			if (i>0) { //nao comeca com X
				g = grundy_x[i];
//				cout << "-x  " << i << " g=" << grundy_x[i] << endl;
			}
			else
				g = 0;
			for(j=i+1;jogo[j]!='\0';j++) {
				if (jogo[j]=='X') {
					g ^= grundyxx[j-i-1];
//					cout << "x-x " << j-i-1 << " g=" << grundyxx[j-i-1] << endl;
					i = j;
				}
			}
			if (jogo[j-1]!='X') { //nao termina com X
				g ^= grundy_x[j-i-1];
//				cout << "x-  " << j-i-1 << " g=" << grundy_x[j-i-1] << endl;
			}
		}
		cout << (g?'S':'N') << endl;
		cin >> n;
	}

	return 0;
}