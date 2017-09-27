#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define D(x) cout << #x " = " << (x) << endl

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
	string impr;
	char num;
	
	while(cin >> num >> impr, num != '0') {		
		bool leadingZeros = true;
		int cont = 0;
		
		for(int i=0; i<impr.size(); i++) {
			if(impr[i] != '0' && impr[i] != num)
				leadingZeros = false;
				
			if(leadingZeros && impr[i] == '0') {
				impr[i] = '*';
				cont++;
			}
			
			if(impr[i] == num) {
				impr[i] = '*';
				cont++;
			}
		}
		
		//cout << impr << endl;
		
		if(cont == impr.size())
			puts("0");
		else {
			for(int i=0; i<impr.size(); i++)
				if(impr[i] != '*')
					printf("%c", impr[i]);
							
			puts("");
		}
	}
}
