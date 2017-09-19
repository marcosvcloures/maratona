#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-10;

inline int cmp( double x, double y = 0, double tol = EPS ) {
    return (x <= y + tol ) ? ( x + tol < y ) ? -1 : 0 : 1;
}

struct Point {
    double x, y;

    Point( double x = 0, double y = 0 ) : x( x ), y( y ) {}

    Point operator+( Point q ) const {
        return Point( x + q.x, y + q.y );
    }

    Point operator-( Point q ) const {
        return Point( x - q.x, y - q.y );
    }

    Point operator*( double t ) const {
        return Point( x * t, y * t );
    }

    Point operator/( double t ) const {
        return Point( x / t, y / t );
    }

    double operator*( Point q )const {
        return x * q.x + y * q.y;
    }

    double operator^( Point q ) const {
        return x * q.y - y * q.x;
    }

    int cmp( Point q ) const {
        if ( int t = ::cmp( x, q.x ) ) 
			return t;
        return ::cmp( y, q.y );
    }

    bool operator==( Point q ) const {
        return cmp( q ) == 0;
    }

    bool operator!=( Point q ) const {
        return cmp( q ) != 0;
    }

    bool operator<( Point q ) const {
        return cmp( q ) < 0;
    }
	
    static Point pivot;
};

Point Point::pivot;

typedef vector<Point> Polygon;

inline double abs( Point& p ) {
    return hypot( p.x, p.y );
}

inline double arg( Point& p ) {
    return atan2( p.y, p.x );
}

//Verifica o sinal do produto vetorial entre os vetores (p-r) e (q - r)
inline int ccw( Point& p, Point& q, Point& r ) {
    return cmp( ( p - r ) ^ ( q - r ) );
}

//calcula o angulo orientado entre os vetores (p-q) e (r - q)
inline double angle( Point& p, Point &q, Point& r ) {
    Point u = p - q, w = r - q;
    return atan2( u ^ w, u * w );
}

//Decide se o ponto p esta sobre a reta que passa por p1p2.
bool pointoSobreReta( Point& p1, Point &p, Point& p2 ) {
    return ccw( p1, p2, p ) == 0;
}

//Decide de p esta sobre o segmento p1p2
bool between( Point& p1, Point &p, Point& p2 ) {
    return ccw( p1, p2, p ) == 0 && cmp( ( p1 - p ) * ( p2 - p ) ) <= 0;
}

//Calcula a distancia do ponto p a reta que passa por p1p2
double retaDistance( Point& p1, Point& p2, Point &p ) {
    Point A = p1 - p, B = p2 - p1;
    return fabs( A ^ B ) / sqrt( B * B );
}

//Calcula a distancia do ponto p ao segmento de reta que passa por p1p2
double segDistance( Point& p1, Point& p2, Point &p ) {
    Point A = p1 - p, B = p1 - p2, C = p2 - p;
    double a = A * A, b = B * B, c = C * C;
    if ( cmp( a, b + c ) >= 0 ) return sqrt( c );
    if ( cmp( c, a + b ) >= 0 )return sqrt( a );
    return fabs( A ^ C ) / sqrt( b );

}
//Calcula a area orientada do poligono T.
double polygonArea( Polygon& T ) {
    double s = 0.0;
    int n = T.size( );
    for ( int i = 0; i < n; i++ )
    {
        s += T[i] ^ T[( i + 1 ) % n];
    }
    return s / 2.0; //Retorna a area com sinal
}
//Classifica o ponto p em relacao ao poligono T dependendo se ele está
//na fronteira (-1) no exterior (0) ou no interior (1).
int inpoly( Point& p, Polygon& T ) {
    //-1 sobre, 0 fora, 1 dentro
    double a = 0.0;
    int n = T.size( );
    for ( int i = 0; i < n; i++ )
    {
        if ( between( T[i], p, T[( i + 1 ) % n] ) ) return -1;
        a += angle( T[i], p, T[( i + 1 ) % n] );
    }
    return cmp( a ) != 0;
}
//Ordenacao radial.
bool radialSort( Point p, Point q ) {
    Point P = p - Point::pivot, Q = q - Point::pivot;
    double R = P ^ Q;
    if ( cmp( R ) ) return R > 0;
    return cmp( P * P, Q * Q ) < 0;
}

//Determina o convex hull de T. ATENCAO. A lista de pontos T e destruida.
Polygon convexHull( vector<Point>& T ) {
    int j = 0, k, n = T.size( );
    Polygon U( n );
    Point::pivot = *min_element( T.begin( ), T.end( ) );
    sort( T.begin( ), T.end( ), radialSort );

    for ( k = n - 2; k >= 0 && ccw( T[0], T[n - 1], T[k] ) == 0; k-- );
    reverse( ( k + 1 ) + T.begin( ), T.end( ) );

    for ( int i = 0; i < n; i++ )
    {
        // troque o >= por > para manter pontos colineares
        while (j > 1 && ccw( U[j - 1], U[j - 2], T[i] ) >= 0) j--;
        U[j++] = T[i];
    }
    U.resize( j );
    return U;
}
//Interseção de semi-retas (p1 -> p2), (p3 -> p4)
bool segIntercept(Point p1, Point p2, Point p3, Point p4) {
	return ccw(p1, p2, p3) != ccw(p1, p2, p4) && ccw(p3, p4, p1) != ccw(p3, p4, p2);
}

