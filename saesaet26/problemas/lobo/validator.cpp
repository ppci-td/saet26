#include "rbx.h"
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  prepareOpts(argc, argv);

  int MIN_N = getVar<int>("N.min"); // Read from package vars.
  int MAX_N = getVar<int>("N.max");

  int MIN_M = getVar<int>("M.min"); // Read from package vars.
  int MAX_M = getVar<int>("M.max");

  int MIN_Q = getVar<int>("Q.min"); // Read from package vars.
  int MAX_Q = getVar<int>("Q.max");

  int n = inf.readInt(MIN_N, MAX_N, "N");
  inf.readSpace();
  int m = inf.readInt(MIN_M, MAX_M, "M");
  inf.readEoln();
  for (int i=0;i<m;i++) {
    int a = inf.readInt(1,n,"a");
    inf.readSpace();
    int b = inf.readInt(1,n,"b");
    inf.readEoln();
  }
  int q = inf.readInt(MIN_Q,MAX_Q);
  inf.readEoln();
  while (q--) {
    int a = inf.readInt(1,n,"a");
    inf.readSpace();
    int b = inf.readInt(1,n,"b");
    inf.readEoln();
  }
  inf.readEof();
}
