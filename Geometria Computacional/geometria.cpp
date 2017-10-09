#include "vec3.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
	Vec3 u(1, 0, 0), v(2, 0, 0), p(1, 0, 1), q(0, 0, 0);
	D(distPontoTriangulo(q, u, v, p));
}
