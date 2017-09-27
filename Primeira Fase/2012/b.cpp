#include <bits/stdc++.h>
using namespace std;

struct Aleta {
    int x1, y1, x2, y2;

    Aleta operator=(Aleta a) {
        x1 = a.x1;
        y1 = a.y1;
        x2 = a.x2;
        y2 = a.y2;
    }
};

double calcNorma(int x1, int y1, int x2, int y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

double dist(Aleta a, Aleta b) {
    double normaFimBFimA = calcNorma(b.x2, b.y2, a.x2, a.y2);
    double normaProj = calcNorma(b.x2, b.y2, b.x1, b.y1);
    double prodEscFimbFimAProj = (a.x2-b.x2)*(b.x1-b.x2) + (a.y2-b.y2)*(b.y1-b.y2);

    return (sqrt((normaFimBFimA*normaFimBFimA)*(normaProj*normaProj) - (prodEscFimbFimAProj*prodEscFimbFimAProj)) / normaProj);
}

int main() {
    int n, l, h, lateral;
    double maior, aux;
    Aleta a, b;


    while(scanf("%d", &n)!=EOF) {
        scanf("%d %d", &l, &h);

        scanf("%d %d %d", &a.y1, &a.x2, &a.y2);
        a.x1 = 0;

        maior = l - a.x2;

        for(int i=1; i<n; i++) {
            scanf("%d %d %d", &b.y1, &b.x2, &b.y2);

            if(i%2==0) {
                b.x1 = 0;
                lateral = l - b.x2;

                if(b.x2 >= a.x2)
                    aux = dist(a, b);
                else
                    aux = calcNorma(b.x2, b.y2, a.x2, a.y2);
            }
            else {
                b.x1 = l;
                lateral = b.x2;

                if(b.x2 <= a.x2)
                    aux = dist(a, b);
                else
                    aux = calcNorma(b.x2, b.y2, a.x2, a.y2);
            }

			maior = min(maior, aux);
			maior = min(maior, (double)lateral);

            a = b;
        }

        printf("%.2lf\n", maior);
    }

    return 0;
}
