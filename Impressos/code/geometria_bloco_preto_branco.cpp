#include <bits/stdc++.h>

using namespace std;

struct Bloco {
    long long qt;
    char c;
};


Bloco bloco[200000];
long long totB, totW;
long long n;


long long getX(long long y) {
	return ceil((totB * y)*1.0/(totW));
}

long long getY(long long x) {
	return ceil((totW * x)*1.0/(totB));
}

int main() {
    long long t;
    cin >> t;


    while(t--) {
        cin >> n;

        totB = totW = 0;

        for(int i=0; i<n; i++) {
            scanf("%lld %c", &bloco[i].qt, &bloco[i].c);
            if(bloco[i].c == 'W')
                totW += bloco[i].qt;
            else
                totB += bloco[i].qt;
        }

        if(totW == 0 || totB == 0) {
            cout << totW + totB << endl;
            continue;
        }

		long long x = 0, y = 0;
		long long x_a = 0, y_a = 0;
		long long cont = 0;
		
        for(int i=0; i<n; i++) {
        	if(i < n-1 && bloco[i].c == bloco[i+1].c) {
        		if(bloco[i].c == 'B')
        			x_a += bloco[i].qt;
        		else
        			y_a += bloco[i].qt;
        	}
        	else {
        		if(bloco[i].c == 'B') {
        			x_a += bloco[i].qt;
        			double local = getX(y);
        			if(local >= x && local < x + x_a)
        				if((totB * y) % totW == 0)
        					cont++;
        			x += x_a;
        			x_a = 0;
        		}
        		else {
        			y_a += bloco[i].qt;
        			double local = getY(x);
        			if(local >= y && local < y + y_a)
        				if((totW * x) % totB == 0)
        					cont++;
        			y += y_a;
        			y_a = 0;
        		}
        	}
        }
        
        cout << cont << endl;
    }

    return 0;
}
