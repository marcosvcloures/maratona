#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl

using namespace std;


int n, c, t1, t2;
int pd[2000];
int furo[2000];

int pdzona(int ini, int i) {
	if(i >= n)
		return 0;

//if(ini == 3 && i==3)
//D(i);
		
	int pos = (i+ini)%n;

	if(pd[pos] != -1)
		return pd[pos];
		
		
	int x, y;

	for(x=i; x<n; ++x) {
		if(x+ini < n) {
			if(furo[x+ini] > furo[(ini+i)%n]+t1)
				break;
		} else {
			if((furo[(ini+i)%n]+t1)-c < furo[(x+ini)%n]) {
				break;
			}
		}
	}
	
	

	for(y=i; y<n; ++y) {
		if(y+ini < n) {
			if(furo[y+ini] > furo[(ini+i)%n]+t2)
				break;
		} else {
			if((furo[(ini+i)%n]+t2)-c < furo[(y+ini)%n]) {
				break;
			}
		}
	}
	
	if(x==i) x++;
	if(y==i) y++;

//cout << pos << ": " << ini << "  " << x << "  " << y << endl;
	int menor = pdzona(ini, x);
	int maior = pdzona(ini, y);
	
	if(menor+t1 < maior+t2)
		pd[pos] = t1+menor;
	else
		pd[pos] = t2+maior;

	return pd[pos];
}

int main() {
while(cin >> n >> c >> t1 >> t2) {
	
	for(int i=0; i<n; ++i)
		scanf("%d", &furo[i]);
		
	int melhor = 156345425;
	for(int i=0; i<n; i++) {
		//cout << i << ": " << endl;
		fill(pd, pd+10+n, -1);
		
		
		melhor = min(melhor, pdzona(i, 0));
		//for(int j=0; j<n; j++)
		//	cout << pd[j] << " ";
		//cout << endl << endl;
	}
	
	cout << melhor << endl;
}
	
	
	
	return 0;
}
