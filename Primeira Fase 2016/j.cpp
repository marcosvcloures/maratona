#include <bits/stdc++.h>

using namespace std;

struct tJogador {
	int h0, h, f0, f, id;

	tJogador(int i, int a, int b, int c, int d) {
		id = i;
		h0 = a;
		h = b;
		f0 = -c;
		f = -d;
	}
};

bool sorth0(tJogador a, tJogador b) {
	if(a.h0 == b.h0)
		return a.h > b.h;

	return a.h0 > b.h0;
}

bool sortf0(tJogador a, tJogador b) {
	if(a.f0 == b.f0)
		return a.f > b.f;

	return a.f0 > b.f0;
}

bool sortid(tJogador a, tJogador b) {
	return a.id < b.id;
}

bool sorth(tJogador a, tJogador b) {
	return a.h > b.h;
}

bool sortf(tJogador a, tJogador b) {
	return a.f > b.f;
}

int main() {
	int n, a, b, c, d, i, j, maxh, maxf, u, p, resp = 0;
	double x;
	vector<tJogador> temp, jogadoresH, jogadoresF, possiveis;
	vector<double> fila;
	deque<pair<int, double> > eventosH, eventosF;

	scanf("%d", &n);

	for(i = 0; i < n; i++)
		scanf("%d %d %d %d", &a, &b, &c, &d), temp.push_back(tJogador(i, a, b, c, d));

	sort(temp.begin(), temp.end(), sorth0);

	maxh = temp[0].h;

	jogadoresH.push_back(temp[0]);

	for(i = 1; i < temp.size(); i++)
		if(temp[i].h > maxh)
			jogadoresH.push_back(temp[i]), maxh = temp[i].h;

	sort(temp.begin(), temp.end(), sortf0);

	maxf = temp[0].f;

	jogadoresF.push_back(temp[0]);

	for(i = 1; i < temp.size(); i++)
		if(temp[i].f > maxf)
			jogadoresF.push_back(temp[i]), maxf = temp[i].h;

	sort(jogadoresF.begin(), jogadoresF.end(), sortid);
	sort(jogadoresH.begin(), jogadoresH.end(), sortid);

	j = 0;
	for(i = 0; i < jogadoresF.size(); i++) {
		while(j < jogadoresH.size() && jogadoresH[j].id < jogadoresF[i].id)
			j++;
		if(j < jogadoresH.size() && jogadoresF[i].id == jogadoresH[j].id)
			possiveis.push_back(jogadoresF[i]);
	}
	/*
	puts("Cansaco:");
	for(i = 0; i < jogadoresF.size(); i++) {
		printf("id: %d\nh: %d*t + %d\nf: %d*t + %d\n\n", jogadoresF[i].id, jogadoresF[i].h, jogadoresF[i].h0, jogadoresF[i].f, jogadoresF[i].f0);
	}
	puts("Habilidade:");
	for(i = 0; i < jogadoresH.size(); i++) {
		printf("id: %d\nh: %d*t + %d\nf: %d*t + %d\n\n", jogadoresH[i].id, jogadoresH[i].h, jogadoresH[i].h0, jogadoresH[i].f, jogadoresH[i].f0);
	}

	sort(possiveis.begin(), possiveis.end(), sorth0);

	puts("Possiveis:");
	for(i = 0; i < possiveis.size(); i++) {
		printf("id: %d\nh: %d*t + %d\nf: %d*t + %d\n\n", possiveis[i].id, possiveis[i].h, possiveis[i].h0, possiveis[i].f, possiveis[i].f0);
	} */

	/*
	for(i = 0; i < possiveis.size(); i++)
		for(j = i+1; j < possiveis.size(); j++) {
			x = ((double) (possiveis[i].h0 - possiveis[j].h0)) / ((double) (possiveis[j].h - possiveis[i].h));

			if(x >= 0)
				fila.push_back(x);

			x = ((double) (possiveis[i].f0 - possiveis[j].f0)) / ((double) (possiveis[j].f - possiveis[i].f));

			if(x >= 0)
				fila.push_back(x);
		}
	*/

	if(possiveis.size() >= 2) {
		possiveis.clear();

		sort(temp.begin(), temp.end(), sorth0);

		maxh = temp[0].h;

		possiveis.push_back(temp[0]);

		for(i = 1; i < temp.size(); i++)
			if(temp[i].h > maxh)
				possiveis.push_back(temp[i]), maxh = temp[i].h;

		sort(temp.begin(), temp.end(), sortf0);

		maxf = temp[0].f;

		possiveis.push_back(temp[0]);

		for(i = 1; i < temp.size(); i++)
			if(temp[i].f > maxf)
				possiveis.push_back(temp[i]), maxf = temp[i].h;

		sort(possiveis.begin(), possiveis.end(), sorth);

		u = 0;
		x = 1;
		while(x >= 0) {
			x = -1e30;
			//puts("wat");

			for(i = u+1; i < possiveis.size(); i++) {
				if(((double) (possiveis[u].h0 - possiveis[i].h0)) / ((double) (possiveis[i].h - possiveis[u].h)) > x) {
					x = ((double) (possiveis[u].h0 - possiveis[i].h0)) / ((double) (possiveis[i].h - possiveis[u].h));
					p = i;
				}
			}

			eventosH.push_front(make_pair(possiveis[u].id, x));
		//	printf("pushh %d %lf\n", 		possiveis[u].id, x);
			u = p;
		}

		sort(possiveis.begin(), possiveis.end(), sortf);

		u = 0;
		x = 1;
		while(x >= 0) {
			x = -1e30;
			//puts("wat");

			for(i = u+1; i < possiveis.size(); i++) {
				if(((double) (possiveis[u].f0 - possiveis[i].f0)) / ((double) (possiveis[i].f - possiveis[u].f)) > x) {
					x = ((double) (possiveis[u].f0 - possiveis[i].f0)) / ((double) (possiveis[i].f - possiveis[u].f));
					p = i;
				}
			}

			eventosF.push_front(make_pair(possiveis[u].id, x));
			//printf("pushf %d %lf\n", 		possiveis[u].id, x);
			u = p;
		}
	/*
		sort(possiveis.begin(), possiveis.end(), sortf0);

		u = possiveis.size() - 1;
		p = possiveis.size() - 2;

		for(a = possiveis.size() - 3; a >= 0; a--) {
			if(((double) (possiveis[p].f0 - possiveis[u].f0)) / ((double) (possiveis[u].f - possiveis[p].f))
			 < ((double) (possiveis[a].f0 - possiveis[p].f0)) / ((double) (possiveis[p].f - possiveis[a].f)))
				p = a;
			else {
				eventosF.push_front(make_pair(possiveis[u].id, ((double) (possiveis[p].f0 - possiveis[u].f0)) / ((double) (possiveis[u].f - possiveis[p].f))));
				u = p;
				p = a;
			}
		}

		eventosF.push_front(make_pair(possiveis[u].id, ((double) (possiveis[p].f0 - possiveis[u].f0)) / ((double) (possiveis[u].f - possiveis[p].f))));
		eventosF.push_front(make_pair(possiveis[p].id, 0)); */
	}
	else {
		printf("%d\n", possiveis.size());

		return 0;
	}

	while(eventosF.size() > 1 && eventosH.size() > 1) {
		if(eventosF.front().first == eventosH.front().first) {
			//printf("%d [%lf - %lf] ~ [%lf - %lf]\n", eventosF.front().first, eventosF.front().second, eventosF[1].second, eventosH.front().second, eventosH[1].second);
			if(eventosF.front().second < eventosH[1].second && eventosF.front().second >= eventosH.front().second
			|| eventosH.front().second < eventosF[1].second && eventosH.front().second >= eventosF.front().second)
			resp++;
		}
		if(eventosF[1].second < eventosH[1].second)
			eventosF.pop_front();
		else
			eventosH.pop_front();
	}

	while(eventosF.size() > 1) {
		if(eventosF.front().first == eventosH.front().first)
			resp++;

		eventosF.pop_front();
	}

	while(eventosH.size() > 1) {
		if(eventosH.front().first == eventosH.front().first)
			resp++;

		eventosH.pop_front();
	}

	printf("%d\n", resp + 1);

	return 0;
}