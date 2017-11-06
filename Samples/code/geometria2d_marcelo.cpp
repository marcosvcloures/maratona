//****************************************************************************//
//****************************************************************************//
//*                                                                          *//
//*                      BEHOLD THE MIGHTY VEC2 LIBRARY                      *//
//*                                                                          *//
//****************************************************************************//
//****************************************************************************//


#include <bits/stdc++.h>
using namespace std;


#define D(x) cout << #x " = " << (x) << endl


typedef double Double;
typedef Double T;
struct Vec2;
typedef vector<Vec2> Polygon;

//int
//#define INF INT_MAX
//Double
#define INF INFINITY


//------------------------------------------------ COMPARACAO DE PONTO FLUTUANTE
static const Double EPS = 1e-10;

// Compara doubles
int cmp(Double x, Double y = 0.0, Double tol = EPS) {
    return (x <= y + tol) ? (x + tol <= y) ? -1 : 0 : 1;
}
//------------------------------------------------------------------------------

//----------------------------------------- COMPARADORES PARA SORT OU OPERATOR <
bool cmpMenorXY(const Vec2 &u, const Vec2 &v);
bool cmpMenorYX(const Vec2 &u, const Vec2 &v);
bool cmpPolar(const Vec2 &u, const Vec2 &v);
//------------------------------------------------------------------------------


struct Vec2 {
	T x, y;

	Vec2(T x = 0, T y = 0) : x(x), y(y) {}
	Vec2(const Vec2 &v) : x(v.x), y(v.y) {}
	Vec2(const Vec2 &u, const Vec2 &v) : x(u.x - v.x), y(u.y - v.y) {}
	Vec2& operator=(const Vec2 &v) { x = v.x; y = v.y; return *this; }

	//----------------------------------------------------- OPERADORES VETORIAIS
	Vec2 operator+(const Vec2 &v) const { return Vec2(x + v.x, y + v.y); }
	Vec2 operator-(const Vec2 &v) const { return Vec2(x - v.x, y - v.y); }
	// Produto escalar
	T operator*(const Vec2 &v) const { return x * v.x + y * v.y; }
	// "Produto vetorial"
	T operator^(const Vec2 &v) const { return x * v.y - y * v.x; }
	//--------------------------------------------------------------------------

	//------------------------------------------------- OPERADORES COM ESCALARES
	Vec2 operator+(const T c) const { return Vec2(x + c, y + c); }
	Vec2 operator-(const T c) const { return Vec2(x - c, y - c); }
	Vec2 operator*(const T c) const { return Vec2(x * c, y * c); }
	Vec2 operator/(const T c) const { return Vec2(x / c, y / c); }
	//--------------------------------------------------------------------------

	//------------------------------------------------------------------- NORMAS
	// Retorna a norma
	Double norma() const { return hypot(x, y); }
	// Retorna norma ao quadrado
	T norma2() const { return x * x + y * y; }
	// Retorna uma copia normalizada do vetor
	Vec2 normalizado() const { return *this / norma(); }
	//--------------------------------------------------------------------------

    //------------------------------------------------------------- COMPARADORES
    //****************** CUIDADO - ADAPTAR AO PROBLEMA *************************
	bool operator==(const Vec2 &v) const {
		//int
		//return x == v.x && y == v.y;
		//Double
		return !cmp(x, v.x) && !cmp(y, v.y);
	}

	bool operator!=(const Vec2 &v) const {
		//int
		//return x != v.x || y != v.x;
		//Double
		return cmp(x, v.x) || cmp(y, v.y);
	}

	bool operator<(const Vec2 &v) const { return cmpMenorXY(*this, v); }
	//--------------------------------------------------------------------------

    //-------------------------------------------------------------------- DEBUG
    friend ostream& operator<<(ostream &os, const Vec2 &v) {
        return os << "(" << v.x << ", " << v.y << ")";
    }
    //--------------------------------------------------------------------------
};


struct Segmento {
	Vec2 a, b;

	Segmento() {}
	Segmento(const Vec2 &a, const Vec2 &b) : a(a), b(b) {}
};


//------------------------------------------------ Vec2 PARA COMPARACOES GLOBAIS
Vec2 pivot;
//------------------------------------------------------------------------------


//------------------------------------------------------------------- AUXILIARES
// Retorna 1 se a, b, e c estao em sentido anti-horario, 0 se sao colineares,
// e -1 se estao em sentido horario
int orientacao(const Vec2 &a, const Vec2 &b, const Vec2 &c) {
	T cross = (b - a) ^ (c - a);
	//int
	//return cross <= 0 ? cross < 0 ? -1 : 0 : 1;
	//Double
	return (cmp(cross) < 1) ? (cmp(cross) == -1) ? -1 : 0 : 1;
}

// O dobro da area definida pelo triangulo de pontos a, b e c (com sinal)
T dobroAreaTriangulo(const Vec2 &a, const Vec2 &b, const Vec2 &c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Retorna o dobro da area do poligono p (sem sinal)
T dobroAreaPoligono(Polygon p) {
    T s = 0;
    for (unsigned int i = 0; i < p.size(); i++)
        s += dobroAreaTriangulo(Vec2(), p[i], p[(i + 1) % p.size()]);
    return abs(s);
}

// (USAR SOMENTE SE T FOR PONTO FLUTUANTE)
// Retorna a projecao de u em v
Vec2 projecao(const Vec2 &u, const Vec2 &v) {
    assert(v.x || v.y);
    return v * ((u * v) / v.norma2());
}
//------------------------------------------------------------------------------

//----------------------------------------------------------------- COMPARADORES
// Compara se u < v coordenada por coordenada
bool cmpMenorXY(const Vec2 &u, const Vec2 &v) {
	//int
	//return u.x != v.x ? u.x < v.x : u.y < v.y;
	//Double
	return cmp(u.x, v.x) ? (cmp(u.x, v.x) == -1) : (cmp(u.y, v.y) == -1);
}

// Compara se u < v coordenada por coordenada
bool cmpMenorYX(const Vec2 &u, const Vec2 &v) {
	//int
	//return u.y != v.y ? u.y < v.y : u.x < v.x;
	//Double
	return cmp(u.y, v.y) ? (cmp(u.y, v.y) == -1) : (cmp(u.x, v.x) == -1);
}

// Compara se u < v no sentido anti-horario
bool cmpPolar(const Vec2 &u, const Vec2 &v) {
	int orient = orientacao(pivot, u, v);
	//int
	//if(orient) return orient > 0;
	//return u * u < v * v;
	//Double
	if(cmp(orient)) return orient > 0;
	return cmp(u * u, v * v) < 0;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------- DISTÂNCIAS
// (USAR SOMENTE SE T FOR PONTO FLUTUANTE)
// Retorna a distância do ponto p ao segmento s
Double distPontoSegmento(const Vec2 &p, const Segmento &s) {
    Vec2 u = s.b - s.a, v = p - s.a;
    Double t = (u * v) / (u * u);
    if(cmp(t) == -1) t = 0.0;
    if(cmp(t, 1.0) == 1) t = 1.0;
    return (p - Vec2(s.a + u * t)).norma();
}

// (USAR SOMENTE SE T FOR PONTO FLUTUANTE)
// Retorna a menor distância entre um ponto qualquer de s1
// com um ponto qualquer de s2
Double distSegmentoSegmento(const Segmento &s1, const Segmento &s2) {
    Vec2 u = s1.b - s1.a,  v = s2.b - s2.a, w = s1.a - s2.a;
    Double a = u * u, b = u * v, c = v * v, d = u * w, e = v * w;
    Double den = a * c - b * b, t1, t2;

    if(cmp(den) == 0) {
        t1 = 0;
        t2 = d / b;
    }
    else {
        t1 = (b * e - c * d) / den;
        t2 = (a * e - b * d) / den;
    }
    
    if(0 <= t1 && t1 <= 1 && 0 <= t2 && t2 <= 1) {
        Vec2 p = s1.a + u * t1, q = s2.a + v * t2;
        return (p - q).norma();
    }
    else {
        Double option1 = min(distPontoSegmento(s2.a, s1),
        	distPontoSegmento(s2.b, s1));
        Double option2 = min(distPontoSegmento(s1.a, s2),
        	distPontoSegmento(s1.b, s2));
        return min(option1, option2);
    }
}

// (USAR SOMENTE SE T FOR PONTO FLUTUANTE)
// Retorna a menor distância entre o ponto p ao triângulo t1t2t3
Double distPontoTriangulo(const Vec2 &p, const Vec2 &t1,
	const Vec2 &t2, const Vec2 &t3) {
    Vec2 u = t2 - t1, v = t3 - t1, n = u ^ v;

    // Se falhar os pontos do triângulo sao colineares
    assert(cmp(n * n) != 0);
    
    // Verificando se p esta dentro do triângulo
    Double w = dobroAreaTriangulo(t1, t2, t3);
    Double a1 = dobroAreaTriangulo(p, t2, t3) / w;
    Double a2 = dobroAreaTriangulo(t1, p, t3) / w;
    Double a3 = dobroAreaTriangulo(t1, t2, p) / w;

    // Temos as coordenadas baricêntricas de p. p == a1*t1 + a2*t2 + a3*t3.
    if (0 <= a1 && a1 <= 1 && 0 <= a2 && a2 <= 1 && 0 <= a3 && a3 <= 1) {
		// O ponto esta dentro do triângulo ou em sua borda.
		// CASO QUEIRA CALCULAR A DISTANCIA DO PONTO A BORDA DO TRIANGULO
		// USAR SEMPRE O CODIGO DO ELSE
        return 0.0;
    }
    else {
		// O ponto mais proximo esta no plano do triângulo.
        Double ans = distPontoSegmento(p, Segmento(t1, t2));
        ans = min(ans, distPontoSegmento(p, Segmento(t2, t3)));
        ans = min(ans, distPontoSegmento(p, Segmento(t3, t1)));
        return ans;
    }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------ INTERSECOES
// Retorna se o ponto p esta no segmento s
bool interPontoSegmento(const Vec2 &p, const Segmento &s) {
	if(orientacao(p, s.a, s.b) != 0)
		return false;

    if (p.x <= max(s.a.x, s.b.x) && p.x >= min(s.a.x, s.b.x) &&
        p.y <= max(s.a.y, s.b.y) && p.y >= min(s.a.y, s.b.y))
       return true;
 
    return false;
}

// (USAR SOMENTE SE T FOR PONTO FLUTUANTE)
// Retorna se os segmentos s1 e s2 se interceptam. Em caso afirmativo
// o ponto de intersecao e atribuido a p.
bool interSegmentoSegmento(const Segmento &s1, const Segmento &s2, Vec2 &p) {
	int o1 = orientacao(s1.a, s1.b, s2.a);
	int o2 = orientacao(s1.a, s1.b, s2.b);
	int o3 = orientacao(s2.a, s2.b, s1.a);
	int o4 = orientacao(s2.a, s2.b, s1.b);

	if(o1 == 0 && o2 == 0)
		return interPontoSegmento(s1.a, s2) || interPontoSegmento(s1.b, s2)
			|| interPontoSegmento(s2.a, s1) || interPontoSegmento(s2.b, s1);

	return o1 != o2 && o3 != o4;
}

// (USAR SOMENTE SE T FOR PONTO FLUTUANTE)
// Atribui a p a lista com todas as intersecoes entre os segmentos de s
// O(nLogn) (Sweep line)
void interSegmentoSegmento(const vector<Segmento> &s, vector<Vec2> &p) {
	// Vec2 operator < deve ser cmpMenorXY
	priority_queue<Vec2> pq; // Pontos ordenados por menor x
	set<Vec2> as; // BST para segmentos ativos

	for(auto &it : s) {
		pq.push(it.a);
		pq.push(it.b);
	}

	//for(int i = 0; i < )
}
//------------------------------------------------------------------------------

//----------------------------------------------------------------------- OUTROS
// Retorna o quadrado da menor distancia entre pares de pontos do conjunto p
// Atribui o par mais proximo a p1 e p2
// O(nLogn) (Sweep line)
T parMaisProximo2(vector<Vec2> &p, Vec2 &p1, Vec2 &p2) {
	sort(p.begin(), p.end(), cmpMenorXY);

	set<Vec2> box;
	box.insert(p[0]);

	T best = INF, dist;
	int left = 0;
	
	for(int i = 1; i < p.size(); i++) {
		while(left < i && p[i].x - p[left].x > best)
			box.erase(p[left++]);

		// OPERADOR < DEVE SER cmpMenorXY
		for(auto it = box.lower_bound(Vec2(p[i].x - best, p[i].y - best));
			it != box.end() && p[i].y + best >= it->y; ++it) {

			dist = (p[i] - *it).norma2();
			if(dist < best) {
				best = dist;
				p1 = p[i];
				p2 = *it;
			}
		}

		box.insert(p[i]);
	}

	return best;
}
//------------------------------------------------------------------------------

//---------------------------------------------------------------- CASCO CONVEXO
// Retorna o casco convexo de p em ch
void convexHull(Polygon &p, Polygon &ch) {
    int n = p.size();
    
    if (n <= 1) {
    	ch = p;
        return;
    }

    int k = 0;

    sort(p.begin(), p.end(), cmpMenorXY);

    ch.resize(n * 2);

    for (int i = 0; i < n; ch[k++] = p[i++])
        for (; k >= 2 && orientacao(ch[k - 2], ch[k - 1], p[i]) == -1; --k)
            ;

    for (int i = n - 2, t = k; i >= 0; ch[k++] = p[i--])
        for (; k > t && orientacao(ch[k - 2], ch[k - 1], p[i]) == -1; --k)
            ;

    ch.resize(k - 1 - (ch[0] == ch[1]));
}

// Graham's scan
void grahamsScan(Polygon &p, Polygon &ch) {
    int j = 0, k, n = p.size();

    Polygon aux = p;
    ch.resize(n);
    
    pivot = *min_element(aux.begin(), aux.end(), cmpMenorYX);
    sort(aux.begin(), aux.end(), cmpPolar);

    for(k = n - 2; k >= 0 && orientacao(aux[0], aux[n - 1], aux[k]) == 0; k--);
    	reverse((k + 1) + aux.begin(), aux.end());

    for(int i = 0; i < n; i++) {
        // troque o >= por > para manter pontos colineares
        while(j > 1 && orientacao(ch[j - 1], ch[j - 2], aux[i] ) >= 0)
        	j--;

        ch[j++] = aux[i];
    }

    ch.resize(j);
}
//------------------------------------------------------------------------------


int main() {
// TESTETESTETESTETESTETESTETESTETESTETESTETESTETESTETESTETESTETESTETESTETESTE
    Vec2 points[] = {
    	{0, 0}, {2, 0}, {1, 0}, {1, 1},
        {3, 0}, {5, 5}, {3, 3}, {0, 3}
    };

    Vec2 points2[] = {
    	{0, 3}, {1, 1}, {2, 2}, {4, 4},
        {0, 0}, {1, 2}, {3, 1}, {3, 3}
    };

    Vec2 points3[] = {
    	{0, 32}, {2, 1}, {5, 5}, {-2, 4},
        {-321, 32}, {1231, 243}, {332, 231}, {343, -1233},
    	{0, 3343}, {1, -231}, {-542, -342}, {234, -234},
        {10, -10}, {31, 542}, {323, 51}, {-653, 3}
    };
/*
// DISTANCIAS
    cout << distPontoSegmento(points2[1], Segmento(points2[2], points2[3])) << " "
    	<< distSegmentoSegmento(Segmento(points2[4], points2[1]), Segmento(points2[5], points2[0])) << " "
    	<< distPontoTriangulo(points2[3], points2[0], points2[1], points2[5]) << endl;
*/
/*
// INTERSECOES
    cout << interSegmentoSegmento(Segmento(points[0], points[1]), Segmento(points[2], points[3]), pivot) << " " << pivot << "\n"
    	<< interSegmentoSegmento(Segmento(points[4], points[5]), Segmento(points[6], points[7]), pivot) << " " << pivot << "\n"
    	<< interSegmentoSegmento(Segmento(points[3], points[4]), Segmento(points[0], points[6]), pivot) << " " << pivot << endl;
*/
/*
// PAR MAIS PROXIMO
    Vec2 p1, p2;
    int id1, id2;
    Polygon p;
    for(auto it : points3)
    	p.push_back(it);

	cout << sqrt(parMaisProximo2(p, p1, p2)) << endl;
	cout << p1 << " " << p2 << " " << endl;
*/
/*
// CASCOS CONVEXOS
    Polygon p, ch;

    for(auto it : points)
    	p.push_back(it);

    grahamsScan(p, ch);

    for(auto it : ch)
    	cout << it << " ";
   	cout << endl;

    convexHull(p, ch);

    for(auto it : ch)
    	cout << it << " ";
   	cout << endl;
*/
}