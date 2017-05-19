#include <stdio.h>
#include <math.h>

struct tPonto {
	double x, y;
	
	tPonto operator+(tPonto a) {
		tPonto b;
		
		b.x = x + a.x;
		b.y = y + a.y;
		
		return b;
	}
	
	tPonto operator=(tPonto a) {
		x = a.x;
		y = a.y;
		
		return *this;
	}
	
	tPonto operator/(int a) {
		x /= a;
		y /= a;
		
		return *this;
	}
	
	tPonto operator-(tPonto a) {
		tPonto b;
		
		b.x = x-a.x;
		b.y = y-a.y;
		
		return b;
	}
	
	void operator-=(tPonto a) {
		x -= a.x;
		y -= a.y;
	}
};

int main() {
	tPonto a, b, c, m, trans;
	double m1, m2, x, y;
	
	scanf("%lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
	
	trans = a;
	a -= trans;
	b -= trans;
	c -= trans;
	
	if(a.y == b.y) {
		printf("%.02lf %.02lf\n", (a.x+b.x)/2.0, c.y);
		return 0;
	}
	
	if(a.x == b.x) {
		printf("%.02lf %.02lf\n", c.x, (a.y+b.y)/2.0);
		return 0;
	}
	
	m = (b-a)/2;
	
	m1 = -m.x/m.y;
	m2 = -1/m1;
	
	x = ((- m1 * m.x) + m.y + m2 * c.x - c.y)/(m2-m1);
	y = m1 * x - m1 * m.x + m.y;
	
	printf("%.02lf %.02lf\n", x + trans.x, y + trans.y);
}