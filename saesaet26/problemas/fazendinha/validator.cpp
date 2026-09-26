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
  int MIN_B = getVar<int>("B.min"); // Read from package vars.
  int MAX_B = getVar<int>("B.max");
  int MIN_T = getVar<int>("T.min"); // Read from package vars.
  int MAX_T = getVar<int>("T.max");

  int n = inf.readInt(MIN_N, MAX_N, "N");
  inf.readSpace();
  int m = inf.readInt(MIN_M, MAX_M, "M");
  inf.readSpace();
  inf.readInt(MIN_T, MAX_T, "T");
  inf.readEoln();
  for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (j) inf.readSpace();
            inf.readInt(MIN_B, MAX_B, "B");
        }
        inf.readEoln();
  }
  inf.readEof();
}
