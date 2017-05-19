#include <bits/stdc++.h>

using namespace std;

int main() {
	int a[3], r;
	
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	
	sort(a, a + 3);
	
	r = a[0];
	
	if(a[0] + 200 < a[1])
		r += a[1] - a[0] - 200;
	
	if(a[1] + 200 < a[2])
		r += a[2] - a[1] - 200;
	
	if(a[2] < 400)
		r += 400 - a[2];
	
	printf("%d\n", r * 100);
}