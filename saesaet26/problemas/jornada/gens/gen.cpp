#include "testlib.h"

using namespace std;

bool valido(double C, double x1, double y1, double x2, double y2) {
    double A = (y1 - C - (y2*x1)/x2 + (C*x1)/x2)/(x1*x1 - x2*x1);
    double B = (y2 - C - A*x2*x2)/x2;
    return ((A > 0) and (B*B - 4.0*A*C < 0));
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int T = 100000;
    printf("%d\n", T);
    while (T--) {
        int C, x1, y1, x2, y2, d1, d2;
        int lim;
        if (rnd.next(0,1)==0)
            lim=10;
        else
            lim=200;
        do {
            C = rnd.next(1,lim);
            x1 = rnd.next(1,lim);
            y1 = rnd.next(1,lim);
            do { x2 = rnd.next(1,lim); } while (x2==x1);
            y2 = rnd.next(1,lim);
            d1 = rnd.next(1,lim-1);
            d2 = rnd.next(d1+1,lim);
        } while (!valido(C,x1,y1,x2,y2));
        printf("%d %d %d %d %d %d %d\n", C, x1, y1, x2, y2, d1, d2);
    }

    return 0;
}
