#include <stdio.h>
#include <string.h>

int a, b, c, i, t, gt[101], players[1000000], roll, ini, fim;

int main() {
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d %d %d", &a, &b, &c);
		
		for (i = 0; i < a; i++)
			players[i] = 1;

		memset(gt, 0, 101 * sizeof(int));

		while (b--) {
			scanf("%d %d", &ini, &fim);

			gt[ini] = fim;
		}

		for (i = 0; i < c; i++) {
			scanf("%d", &roll);

			int &atual = players[i % a];
			
			atual += roll;

			if (gt[atual])
				atual = gt[atual];
			
			if (atual >= 100) {
				atual = 100;
				break;
			}
		}

		for(i++; i < c; i++)
			scanf("%*d");

		for (i = 0; i < a; i++)
			printf("Position of player %d is %d.\n", i + 1, players[i]);
	}
}