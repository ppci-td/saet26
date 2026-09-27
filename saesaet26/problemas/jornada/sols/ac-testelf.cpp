#include <bits/stdc++.h>

using namespace std;

int main() {

    int T;
    double C,x1,y1,x2,y2,d1,d2;
    for(scanf("%d",&T);T--;) {
        scanf("%lf %lf %lf %lf %lf %lf %lf", &C, &x1, &y1, &x2, &y2, &d1, &d2);
        double A = (y1 - C - (y2*x1)/x2 + (C*x1)/x2)/(x1*x1 - x2*x1);
        double B = (y2 - C - A*x2*x2)/x2;
        double F2 = A*d2*d2*d2/3.0 + B*d2*d2/2.0 + C*d2;
        double F1 = A*d1*d1*d1/3.0 + B*d1*d1/2.0 + C*d1;
//        printf("A = %lf B = %lf C = %lf\n",A,B,C);
        printf("%.30lf\n",F2-F1);
    }

    return 0;
}
