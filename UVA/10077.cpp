#include <bits/stdc++.h>
using namespace std;

int n, d, mina, minb, maxa, maxb, x, y;

void find(){
	if(n == x and d == y){
		return;
	} else if (x * d < y * n){
		maxa = n;
		maxb = d;
		cout << "L";
	} else {
		mina = n;
		minb = d;
		cout << "R";
	}
	
	n = mina + maxa;
	d = minb + maxb;
	find();
	return;
	
}

int main(){
	while(true){
		cin >> x >> y;
		if(x == 1 and y == 1){
			break;
		}
		n = 1;
		d = 1;
		mina = 0;
		minb = 1;
		maxa = 1;
		maxb = 0;
		find();
		cout << endl;
	}
	return 0;
}
