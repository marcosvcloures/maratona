#include <bits/stdc++.h>

using namespace std;

int main() {	
	int total, count;
	char l, pal[1000];
	
	scanf(" %c", &l);
	
	while(scanf(" %s", &pal) > 0) {
		if(strchr(pal, l))
			count++;
		total++;
	}
	
	printf("%.1lf\n", count * 100.0 / total);
}