#include <bits/stdc++.h>

using namespace std;

struct tVertice {
	int id, pai;
	long long int dist;

	tVertice(int a, long long int b, int p = -1) {
		id = a;
		dist = b;
		pai = p;
	}

	bool operator<(tVertice a) const {
		return a.dist < dist;
	}
};

struct tGrafo {
	vector<tVertice> *Grafo;
	int n, *pais;

	tGrafo(int a) {
		Grafo = new vector<tVertice>[a];
		pais = new int[a];
		n = a;
	}

	~tGrafo() {
		limpa();
		delete[] pais;
		delete[] Grafo;
	}

	void operator=(tGrafo const &a) {
		limpa();

		for (int i = 0; i < n; i++)
			for (int j = 0; j < a.Grafo[i].size(); j++)
				Grafo[i].push_back(a.Grafo[i][j]);
	}

	void limpa() {
		for (int i = 0; i < n; i++)
			Grafo[i].clear();
	}

	void addAresta(int a, int b, long long int v = 0) {
		Grafo[a].push_back(tVertice(b, v));
	}

	void removeAresta(int a, int b) {
		for (int i = 0; i < Grafo[a].size(); i++)
			if (Grafo[a][i].id == b) {
				Grafo[a].erase(Grafo[a].begin() + i);
				return;
			}
	}



	long long int Dijkstra(int inicio, int fim) {
		priority_queue<tVertice> fila;
		bool visitados[n];
		int i;

		for (i = 0; i < n; i++)
			pais[i] = visitados[i] = 0;

		fila.push(tVertice(inicio, 0));

		while (fila.top().id != fim && !fila.empty()) {
			if (!visitados[fila.top().id]) {
				for (i = 0; i < Grafo[fila.top().id].size(); i++)
					if (!visitados[Grafo[fila.top().id][i].id])
						fila.push(tVertice(Grafo[fila.top().id][i].id, fila.top().dist + Grafo[fila.top().id][i].dist, fila.top().id));

				visitados[fila.top().id] = 1;
				pais[fila.top().id] = fila.top().pai;
			}

			fila.pop();
		}

		if (fila.empty())
			return -1;

		pais[fila.top().id] = fila.top().pai;

		return fila.top().dist;
	}

	// Retorna a MST, caso queira retornar o custo, basta retornar a variável custo.
	tGrafo Prim(int inicio) {
		priority_queue<tVertice> fila;
		tGrafo G2(n);
		bool visitados[n];
		int i, custo = 0;

		fila.push(tVertice(inicio, 0));

		while (!fila.empty()) {
			if (!visitados[fila.top().id]) {
				for (i = 0; i < Grafo[fila.top().id].size(); i++)
					if (!visitados[Grafo[fila.top().id][i].id])
						fila.push(tVertice(Grafo[fila.top().id][i].id, Grafo[fila.top().id][i].dist, fila.top().id));

				custo += fila.top().dist;
				visitados[fila.top().id] = 1;
				G2.addAresta(fila.top().pai, fila.top().id);
			}

			fila.pop();
		}

		return G2;
	}

	long long int buscaLargura(int inicio, int fim) {
		queue<tVertice> fila;
		bool visitados[n];
		int i;

		for (i = 0; i < n; i++)
			visitados[i] = pais[i] = 0;

		fila.push(tVertice(inicio, 0));

		while (fila.front().id != fim && !fila.empty()) {
			if (!visitados[fila.front().id]) {
				for (i = 0; i < Grafo[fila.front().id].size(); i++)
					if (!visitados[Grafo[fila.front().id][i].id])
						fila.push(tVertice(Grafo[fila.front().id][i].id, fila.front().dist + 1, fila.front().id));

				visitados[fila.front().id] = 1;
				pais[fila.front().id] = fila.front().pai;
			}

			fila.pop();
		}

		if (fila.empty())
			return -1;

		pais[fila.front().id] = fila.front().pai;

		return fila.front().dist;
	}

	long long int fordFulkerson(int s, int t) {
		int u, v;
		long long int max_flow = 0;

		while (buscaLargura(s, t) >= 0) {
			long long int path_flow = 10000000000;

			for (v = t; v != s; v = pais[v]) {
				u = pais[v];
				path_flow = min(path_flow, valAresta(u, v));
			}

			for (v = t; v != s; v = pais[v]) {
				u = pais[v];
				modificaAresta(u, v, -path_flow);
				modificaAresta(v, u, path_flow);
			}

			max_flow += path_flow;
		}

		return max_flow;
	}


	long long int valAresta(int a, int b) {
		for (int i = 0; i < Grafo[a].size(); i++)
			if (Grafo[a][i].id == b)
				return Grafo[a][i].dist;
		return -1;
	}

	void modificaAresta(int a, int b, long long int v) {
		for (int i = 0; i < Grafo[a].size(); i++)
			if (Grafo[a][i].id == b) {
				Grafo[a][i].dist += v;

				if (Grafo[a][i].dist == 0)
					Grafo[a].erase(Grafo[a].begin() + i);

				return;
			}
		addAresta(a, b, v);
	}

	bool existeAresta(int a, int b) {
		for (int i = 0; i < Grafo[a].size(); i++)
			if (Grafo[a][i].id == b)
				return true;
		return false;
	}
};

int main() {
	char linha[200], total;

reset:
	tGrafo grafo(200);

	total = 0;

	for (int i = '0'; i <= '9'; i++)
		grafo.addAresta(i, 199, 1);

	while (scanf("%[^\n]%*c", linha) > 0) {
		total += linha[1] - '0';

		grafo.addAresta(198, linha[0], linha[1] - '0');

		for (int i = 3; i < strlen(linha); i++)
			grafo.addAresta(linha[0], linha[i], 1);
	}

	if (total) {
		if (grafo.fordFulkerson(198, 199) == total) {
			for (int i = '0'; i <= '9'; i++)
				if (grafo.Grafo[i][0].id != 199)
					printf("%c", grafo.Grafo[i][0].id);
				else
					printf("_");
			printf("\n");
		}
		else
			puts("!");

		scanf("%*c");

		goto reset;
	}
}