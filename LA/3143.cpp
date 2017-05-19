#include <bits/stdc++.h>

using namespace std;

char v[2000];

char func(int c, int pos) {
	if (c > 26)
		func((c - 1) / 26, pos + 1);
	else
		v[pos + 1] = 0;

	v[pos] = (c - 1) % 26 + 'A';
}

int main()
{
	int r, c, i;
	
	while (scanf(" R%dC%d", &r, &c) && (r || c))
	{
		func(c, 0);

		reverse(v, v + strlen(v));

		printf("%s%d\n", v, r);
	}
}