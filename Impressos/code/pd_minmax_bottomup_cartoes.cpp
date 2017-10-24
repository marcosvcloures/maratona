#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl;

using namespace std;

int main() {
	int n;
	
	long long cartoes[12000];
	long long A[12000];
	long long W[12000];
	
	while(cin >> n) {
		for(int i=0; i<n; i++) {
			scanf("%lld", &cartoes[i]);
			A[i] = W[i] = 0;
		}
		
		for(int i=1; i<n; i++) {
			for(int j=0; j<n-i; j++) {
				if(i%2 == 0) 
					W[j] = min(A[j], A[j+1]);
				else
					A[j] = max( (cartoes[j] + W[j+1]),
								(cartoes[j+i] + W[j]));
			}
		}
		
		cout << A[0] << endl;
	}

	return 0;
}
