#include <stdio.h>

int main() {
	int n, h = 0, m = 0, s = 0, em, es;
	
	scanf("%d", &n);
	
	while(n--) {
		scanf("%d%*c%d", &em, &es);
		
		m += em;
		s += es;
	}
	
	m += s/60;
	s %= 60;
	
	h += m/60;
	m %= 60;
	
	printf("%02d:%02d:%02d\n", h, m, s);
}