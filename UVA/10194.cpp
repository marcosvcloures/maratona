#include <bits/stdc++.h>

using namespace std;

string lower(char *pal) {
	string resp;

	while (*pal != 0)
		resp += tolower(*pal), pal++;

	return resp;
}

struct Time {
	string nome, lnome;
	int golsPro, golsContra, vitorias, derrotas, empates, saldo, pontos, jogos;

	bool operator<(const Time &a) const {
		if (pontos != a.pontos)
			return pontos < a.pontos;
		if(vitorias != a.vitorias)
			return vitorias < a.vitorias;
		if (empates != a.empates)
			return empates < a.empates;
		if (saldo != a.saldo)
			return saldo < a.saldo;
		if (golsPro != a.golsPro)
			return golsPro < a.golsPro;
		if (derrotas != a.derrotas)
			return derrotas > a.derrotas;

		return lnome > a.lnome;
	}
};

int main() {
	int t, n, primeiro = true, gols1, gols2, i;
	char nomeCampeonato[200], nome[200], time1[200], time2[200];
	map<string, Time> times;
	map<Time, string> hehe;
	Time vazio;

	vazio.golsContra = vazio.golsPro = vazio.vitorias = vazio.jogos = vazio.derrotas = vazio.empates = vazio.saldo = vazio.pontos = 0;

	scanf(" %d ", &t);

	while (t--) {
		times.clear();
		hehe.clear();

		fgets(nomeCampeonato, 200, stdin);
		scanf(" %d ", &n);

		for (i = 0; i < n; i++) {
			scanf(" %[^\n] ", nome);

			times[nome] = vazio;

			times[nome].nome = nome;
			times[nome].lnome = lower(nome);
		}

		scanf(" %d ", &n);

		for (i = 0; i < n; i++) {
			scanf(" %[^#]#%d@%d#%[^\n] ", time1, &gols1, &gols2, time2);
		
			if (gols1 > gols2) {
				times[time1].vitorias++;
				times[time1].pontos += 3;
				times[time2].derrotas++;
			}
			else if (gols2 > gols1) {
				times[time2].vitorias++;
				times[time2].pontos += 3;
				times[time1].derrotas++;
			}
			else {
				times[time1].empates++;
				times[time2].empates++;
				times[time1].pontos++;
				times[time2].pontos++;
			}
			times[time1].jogos++;
			times[time2].jogos++;
			times[time1].golsPro += gols1;
			times[time1].golsContra += gols2;
			times[time1].saldo += gols1 - gols2;
			times[time2].golsPro += gols2;
			times[time2].golsContra += gols1;
			times[time2].saldo += gols2 - gols1;
		}

		for (map<string, Time>::iterator it = times.begin(); it != times.end(); it++)
			hehe[(*it).second] = (*it).first;

		if (!primeiro)
			printf("\n");
		else
			primeiro = false;

		printf("%s", nomeCampeonato);

		i = 1;
		for (map<Time, string>::reverse_iterator it = hehe.rbegin(); it != hehe.rend(); it++, i++) {
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i, (*it).second.c_str(), (*it).first.pontos,
				(*it).first.jogos, (*it).first.vitorias, (*it).first.empates, (*it).first.derrotas, 
				(*it).first.saldo, (*it).first.golsPro, (*it).first.golsContra);
		}
	}
}