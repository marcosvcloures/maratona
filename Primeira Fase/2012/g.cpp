#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	
	int m1[100];
	int m2[100];
	while(cin >> n) {
		for(int i=0; i<n; i++)
			scanf("%d", &m1[i]);
		
		for(int i=0; i<n; i++)
			scanf("%d", &m2[i]);
			
		int cont = 0;
		for(int i=0; i<n; i++) {
			for(int j=i; j<n; j++) {
				if(m1[i] == m2[j]) {
					while(j>i) {
						cont++;
						swap(m2[j-1], m2[j]);
						j--;
					}
					break;
				}
			}
		}
		
		cout << cont << endl;
	}

	return 0;
}
