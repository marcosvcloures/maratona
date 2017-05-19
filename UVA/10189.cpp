#include <stdio.h>

int main() {
	int i, j, n, m, mat[102][102] = { 0 }, round = 0, ii, jj;

	while (scanf("%d %d", &n, &m) > 0 && n != 0 && m != 0) {
		printf("%sField #%d:\n", round == 1 ? "" : "\n", ++round);

		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				scanf(" %c", &mat[i][j]), mat[i][j] = mat[i][j] == '.' ? '0' : '*';

		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				if (mat[i][j] == '*')
					for (ii = -1; ii <= 1; ii++)
						for (jj = -1; jj <= 1; jj++)
							mat[i + ii][j + jj] += mat[i + ii][j + jj] != '*';

		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++)
				printf("%c", mat[i][j]);
			printf("\n");
		}
	}
}