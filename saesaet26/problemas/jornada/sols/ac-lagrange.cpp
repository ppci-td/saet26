#include <bits/stdc++.h>

using namespace std;

struct Parabola {
    double A, B, C;
};

Parabola lagrange(double x1, double y1,
                  double x2, double y2,
                  double C)
{
    // Termo associado a (x1, y1)
    double k1 = y1 / ((x1 - x2) * x1);

    // Termo associado a (x2, y2)
    double k2 = y2 / ((x2 - x1) * x2);

    // Termo associado a (0, C)
    double k3 = C / (x1 * x2);

    double A = k1 + k2 + k3;

    double B = -k1 * x2
             - k2 * x1
             - k3 * (x1 + x2);

    return {A, B, C};
}

int main() {

    int T;
    double C,x1,y1,x2,y2,d1,d2;
    for(scanf("%d",&T);T--;) {
        scanf("%lf %lf %lf %lf %lf %lf %lf", &C, &x1, &y1, &x2, &y2, &d1, &d2);
        Parabola p = lagrange(x1,y1,x2,y2,C);
        double F2 = p.A*d2*d2*d2/3.0 + p.B*d2*d2/2.0 + p.C*d2;
        double F1 = p.A*d1*d1*d1/3.0 + p.B*d1*d1/2.0 + p.C*d1;
//        printf("A = %lf B = %lf C = %lf\n",A,B,C);
        printf("%.10lf\n",F2-F1);
    }

    return 0;
}
