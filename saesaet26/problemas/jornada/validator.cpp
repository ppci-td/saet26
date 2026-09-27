#include "rbx.h"
#include "testlib.h"
#include "assert.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  prepareOpts(argc, argv);

  int MIN_N = getVar<int>("N.min"); // Read from package vars.
  int MAX_N = getVar<int>("N.max");
  int MIN_T = getVar<int>("T.min"); // Read from package vars.
  int MAX_T = getVar<int>("T.max");

  int T = inf.readInt(MIN_T, MAX_T);
  inf.readEoln();
  while (T--) {
        int c = inf.readInt(MIN_N,MAX_N);
        inf.readSpace();
        int xx1 = inf.readInt(MIN_N,MAX_N);
        inf.readSpace();
        int yy1 = inf.readInt(MIN_N,MAX_N);
        inf.readSpace();
        int xx2 = inf.readInt(MIN_N,MAX_N);
        inf.readSpace();
        int yy2 = inf.readInt(MIN_N,MAX_N);
        inf.readSpace();
        int dd1 = inf.readInt(MIN_N,MAX_N);
        inf.readSpace();
        int dd2 = inf.readInt(MIN_N,MAX_N);
        inf.readEoln();

        assert(xx1 != xx2);

        double C = c;
        double x1 = xx1;
        double x2 = xx2;
        double y1 = yy1;
        double y2 = yy2;
        double d1 = dd1;
        double d2 = dd2;
        double A = (y1 - C - (y2*x1)/x2 + (C*x1)/x2)/(x1*x1 - x2*x1);
        double B = (y2 - C - A*x2*x2)/x2;
        assert(A > 0);
        assert(B*B - 4.0*A*C < 0);
  }
  inf.readEof();
}
