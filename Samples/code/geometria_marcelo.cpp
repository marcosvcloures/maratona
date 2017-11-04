#include <bits/stdc++.h>
using namespace std;

#define D(x) cout << #x " = " << x << endl

//INT_MAX, UINT_MAX, LLONG_MAX, ULLONG_MAX, INFINITY

// Mudar para double dependendo do exercicio
typedef double Double;

static const Double EPS = 1e-10;

// Compara doubles
int cmp(Double x, Double y = 0.0, Double tol = EPS)
{
    return (x <= y + tol) ? (x + tol <= y) ? -1 : 0 : 1;
}

struct Vec3
{
    Double x, y, z;

    Vec3() : x(0.0), y(0.0), z(0.0) {}
    Vec3(Double x, Double y, Double z) : x(x), y(y), z(z) {}
    Vec3(const Vec3 &u, const Vec3 &v) : x(v.x - u.x), y(v.y - u.y), z(v.z - u.z) {}
    Vec3(const Vec3 &v) : x(v.x), y(v.y), z(v.z) {}

    void operator=(const Vec3 &v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
    }

    //----------------------------------------------------- OPERADORES VETORIAIS
    Vec3 operator+(const Vec3 &v) const
    {
        return Vec3(x + v.x, y + v.y, z + v.z);
    }

    Vec3 operator-(const Vec3 &v) const
    {
        return Vec3(x - v.x, y - v.y, z - v.z);
    }

    // Produto escalar
    double operator*(const Vec3 &v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    // Produto vetorial
    Vec3 operator^(const Vec3 &v) const
    {
        return Vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }

    //--------------------------------------------------------------------------

    //------------------------------------------------- OPERADORES COM ESCALARES
    Vec3 operator+(const Double c) const
    {
        return Vec3(x + c, y + c, z + c);
    }

    Vec3 operator-(const Double c) const
    {
        return Vec3(x - c, y - c, z - c);
    }

    Vec3 operator*(const Double c) const
    {
        return Vec3(x * c, y * c, z * c);
    }

    Vec3 operator/(const Double c) const
    {
        assert(::cmp(c) != 0);
        return Vec3(x / c, y / c, z / c);
    }
    //-------------------------------------------------------------------------

    //------------------------------------------------------------------ NORMAS
    // Retorna a norma
    Double norma() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    // Retorna a norma ao quadrado
    Double norma2() const
    {
        return x * x + y * y + z * z;
    }

    // Retorna uma copia normalizada do vetor
    Vec3 normalizado() const
    {
        return *this / this->norma();
    }
    //--------------------------------------------------------------------------

    //------------------------------------------------------------- COMPARADORES
    //****************** CUIDADO - ADAPTAR AO PROBLEMA *************************
    bool operator==(const Vec3 &v) const
    {
        return !cmp(x, v.x) && !cmp(y, v.y) && !cmp(z, v.z);
    }

    bool operator!=(const Vec3 &v) const
    {
        return !(*this == v);
    }

    // Critehrios de comparacao
    bool operator<(const Vec3 &v) const
    {
        return cmpMenorXYZ(v);
    }

    // Compara componentes na ordem x, y, z.
    // Retorna true assim que encontrar a primeira menor
    bool cmpMenorXYZ(const Vec3 &v) const
    {
        int aux = cmp(x, v.x);

        if(aux < 0)
            return true;
        else if(aux == 0)
        {
            aux = cmp(y, v.y);

            if(aux < 0 || aux == 0 && cmp(z, v.z) < 0)
                return true;
        }

        return false;
    }
    //--------------------------------------------------------------------------

    //-------------------------------------------------------------------- DEBUG
    friend ostream &operator<<(ostream &os, const Vec3 &v)
    {
        return os << "(" << v.x << ", " << v.y << ", " << v.z << ") ";
    }
    //--------------------------------------------------------------------------
};

//------------------------------------------------------------------- AUXILIARES
// Retorna se os pontos a, b, c estao em sentido horario
bool cw(Vec3 a, Vec3 b, Vec3 c)
{
    return cmp((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)) < 0;
}

//O dobro da area definida pelo triangulo de pontos pontos a, b e c (com sinal).
Double area2(Vec3 a, Vec3 b, Vec3 c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

//Retorna a area do poligono p
Double areaPoligono(vector<Vec3> &p)
{
    Double s = 0.0;
    for (unsigned int i = 0; i < p.size(); i++)
        s += area2(Vec3(), p[i], p[(i + 1) % p.size()]);

    return fabs(s / 2.0);
}

// Retorna a projecao de u em v
Vec3 projecao(const Vec3 &u, const Vec3 &v)
{
    assert(v.x || v.y || v.z);
    return v * (u * v / v.norma2());
}

// (u ^ v) * w = [[ux, uy, uz], [vx, vy, vz], [wx, wy, wz]]
Double produtoMisto(const Vec3 &u, const Vec3 &v, const Vec3 &w)
{
    return (u ^ v) * w;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------- DISTÂNCIAS
// Retorna a distância do ponto p ao segmento ab
Double distPontoSegmento(const Vec3 &p, const Vec3 &a, const Vec3 &b)
{
    Vec3 u = b - a, v = p - a;
    Double t = (u * v) / (u * u);
    if(cmp(t) == -1) t = 0.0;
    if(cmp(t, 1.0) == 1) t = 1.0;
    return (p - Vec3(a + u * t)).norma();
}

// Retorna a menor distância entre um ponto qualquer de a1b1 com um ponto qualquer de a2b2
Double distSegmentoSegmento(const Vec3 &a1, const Vec3 &b1, const Vec3 &a2, const Vec3 &b2)
{
    Vec3 u = b1 - a1,  v = b2 - a2, w = a1 - a2;
    Double a = u * u, b = u * v, c = v * v, d = u * w, e = v * w, den = a * c - b * b, t1, t2;

    if(cmp(den) == 0)
    {
        t1 = 0;
        t2 = d / b;
    }
    else
    {
        t1 = (b * e - c * d) / den;
        t2 = (a * e - b * d) / den;
    }

    if(0 <= t1 && t1 <= 1 && 0 <= t2 && t2 <= 1)
    {
        Vec3 p = a1 + u * t1, q = a2 + v * t2;
        return (p - q).norma();
    }
    else
    {
        Double option1 = min(distPontoSegmento(a2, a1, b1), distPontoSegmento(b2, a1, b1));
        Double option2 = min(distPontoSegmento(a1, a2, b2), distPontoSegmento(b1, a2, b2));
        return min(option1, option2);
    }
}

// Retorna a menor distância entre o ponto p ao triângulo t1t2t3
Double distPontoTriangulo(const Vec3 &p, const Vec3 &t1, const Vec3 &t2, const Vec3 &t3)
{
    Vec3 u = t2 - t1, v = t3 - t1, n = u ^ v;

    // Se falhar os pontos do triângulo sao colineares
    assert(cmp(n * n) != 0);

    Double s = -(n * (p - t1)) / (n * n);

    // q eh o ponto do plano do triângulo mais proximo de p
    Vec3 q = p + n * s;

    // Verificando se q esta dentro do triângulo
    Vec3 w = q - t1;
    Vec3 nv = n ^ v;
    Vec3 nu = n ^ u;
    Double a2 = (w * nv) / (u * nv);
    Double a3 = (w * nu) / (v * nu);
    Double a1 = 1 - a2 - a3;

    // Temos as coordenadas baricêntricas de q. q == a1*t1 + a2*t2 + a3*t3.
    if (0 <= a1 && a1 <= 1 && 0 <= a2 && a2 <= 1 && 0 <= a3 && a3 <= 1)
    {
        // O ponto esta dentro do triângulo ou em sua borda.
        // Basta retornar a distância de p a q
        return (p - q).norma();
    }
    else
    {
        // O ponto mais proximo esta no plano do triângulo.
        Double ans = distPontoSegmento(p, t1, t2);
        ans = min(ans, distPontoSegmento(p, t2, t3));
        ans = min(ans, distPontoSegmento(p, t3, t1));
        return ans;
    }
}
//------------------------------------------------------------------------------
//---------------------------------------------------------------- CASCO CONVEXO
// Retorna o casco convexo do conjunto de pontos p em sentido ANTI-HORaRIO
vector<Vec3> convexHull(vector<Vec3> &p)
{
    int n = p.size();

    if (n <= 1)
        return p;

    int k = 0;

    // CUIDADO COM O OPERADOR <
    sort(p.begin(), p.end());

    vector<Vec3> q(n * 2);

    for (int i = 0; i < n; q[k++] = p[i++])
        for (; k >= 2 && cw(q[k - 2], q[k - 1], p[i]); --k)
            ;

    for (int i = n - 2, t = k; i >= 0; q[k++] = p[i--])
        for (; k > t && cw(q[k - 2], q[k - 1], p[i]); --k)
            ;

    q.resize(k - 1 - (q[0] == q[1]));

    return q;
}
//------------------------------------------------------------------------------

int main()
{
    Vec3 u(1, 0, 0), v(2, 0, 0), p(1, 0, 1), q(0, 0, 0);
    D(distPontoTriangulo(q, u, v, p));
}
