#include <bits/stdc++.h>

using namespace std;

inline double f(double A, double B, double C, double x) {
    return A*x*x + B*x + C;
}

int main() {

    int T;
    double C,x1,y1,x2,y2,d1,d2;
    for(scanf("%d",&T);T--;) {
        scanf("%lf %lf %lf %lf %lf %lf %lf", &C, &x1, &y1, &x2, &y2, &d1, &d2);
        double A = (y1 - C - (y2*x1)/x2 + (C*x1)/x2)/(x1*x1 - x2*x1);
        double B = (y2 - C - A*x2*x2)/x2;

        double soma = 0;
        double delta = (d2-d1)/1000;
        for (double x=d1;x+delta<=d2;x+=delta)
            soma += f( A,B,C, (x+x+delta)/2.0 )*delta;

        printf("%.10lf\n",soma);
    }

    return 0;
}
