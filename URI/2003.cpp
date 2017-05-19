#include <stdio.h>

int a(int b) {
	return b > 0 ? b : 0;
}

int main() {
	int h, m;
	
	while(scanf("%d%*c%d", &h, &m) > 0) {
		printf("Atraso maximo: %d\n", a(h*60+m - 420));
	}
}