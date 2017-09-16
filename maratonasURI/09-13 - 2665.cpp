#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-10;

inline int cmp( double x, double y = 0, double tol = EPS ) {
    return (x <= y + tol ) ? ( x + tol < y ) ? -1 : 0 : 1;
}

struct Point {
    double x, y;
    vector<int> filhos;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point operator-(Point q) const {
        return Point( x - q.x, y - q.y );
    }

    double operator^( Point q ) const {
        return x * q.y - y * q.x;
    }
};

inline int ccw( Point& p, Point& q, Point& r ) {
    return cmp( ( p - r ) ^ ( q - r ) );
}

int pdzona[1000];
vector<Point> pontos;

int calcPD(int i, int cont) {
	if(pdzona[i] != -1)
		return pdzona[i];
	if(pontos[i].filhos.size() == 0)
		return 1;
		
	int maior = 0;
	
	for(auto it : pontos[i].filhos)
		maior = max(maior, calcPD(it, cont+1));
	
	pdzona[i] = maior+1;
	return maior+1;
}

int main() {
	int n;
	double a, b;
	
	cin >> n >> a >> b;
	
	for(int i=0; i<n+10; i++)
		pdzona[i] = -1;

	Point A(a, 0.0);
	Point B(b, 0.0);

	for(int i=0; i<n; i++) {
		scanf("%lf%lf", &a, &b);
		pontos.push_back(Point(a,b));
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(i==j) continue;
			
			if(ccw(A, B, pontos[j]) > 0 &&
			   ccw(B, pontos[i], pontos[j]) > 0 &&
			   ccw(pontos[i], A, pontos[j]) > 0)
				pontos[i].filhos.push_back(j);
		}
	}
	
	int maior = -1;
	for(int i=0; i<n; i++) {
		pdzona[i] = calcPD(i, 0);
		maior = max(maior, pdzona[i]);
	}
		
	cout << maior << endl;
	
	
	return 0;
}
