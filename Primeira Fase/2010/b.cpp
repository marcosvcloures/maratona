#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define D(x) // cout << #x " = " << (x) << endl

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> ii;
typedef vector<ii> vii;

#define norte 0
#define sul 2
#define leste 1
#define oeste 3

char mat[200][200];
int orientacao, posi, posj;

int anda(int orientacao) {
	int i = 0, j = 0;
	
	if(orientacao == norte) 
		i--;
	else if(orientacao == sul) 
		i++;
	else if(orientacao == leste) 
		j++;
	else if(orientacao == oeste) 
		j--;
		
	D(mat[posi + i][posj + j]);
	D(i);
	D(j);
		
	if(mat[posi + i][posj + j] != '#') 
		posi += i,
		posj += j;
		
	D(posi);
	D(posj);
		
	if(mat[posi][posj] == '*') {
		mat[posi][posj] = '.';
		
		return 1;
	}
	
	return 0;
}

int main() {
	char acao;
	int n, m, s, orientacao, i, j, resp;
	
	while(scanf("%d %d %d", &n, &m, &s) && n) {
		fill(mat[0], mat[0] + 200 * 200, '#');
		resp = 0;
		
		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++) {
				scanf(" %c", &mat[i][j]);
				
				if(mat[i][j] == 'N') {
					orientacao = norte;
					goto setpos;
				}
				else if(mat[i][j] == 'S') {
					orientacao = sul;
					goto setpos;
				}
				else if(mat[i][j] == 'L') {
					orientacao = leste;
					goto setpos;
				}
				else if(mat[i][j] == 'O') {
					orientacao = oeste;
					goto setpos;
				}
				
				if(false) {
					setpos:
					
					posi = i;
					posj = j;
				}
			}
			
		while(s--) {
			scanf(" %c", &acao);
			
			if(acao == 'F') 
				resp += anda(orientacao);
			else if(acao == 'D') 
				orientacao = (orientacao + 1) % 4;
			else if(acao == 'E') 
				orientacao = (orientacao + 4 - 1) % 4;
		}
		
		printf("%d\n", resp);
	}
}
