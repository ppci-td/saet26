#include "rbx.h"
#include "testlib.h"
#include "assert.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  prepareOpts(argc, argv);

  int MIN_N = getVar<int>("N.min"); // Read from package vars.
  int MAX_N = getVar<int>("N.max");
  int MIN_M = getVar<int>("M.min"); // Read from package vars.
  int MAX_M = getVar<int>("M.max");

  int N = inf.readInt(MIN_N, MAX_N, "N");
  inf.readSpace();
  int M = inf.readInt(MIN_M, MAX_M, "M");
  inf.readEoln();
  string s = inf.readString("[a-z]*");
  assert(s.size() == N);
  for (int i=0;i<M;i++) {
        int L = inf.readInt(MIN_N, MAX_N, "L");
        inf.readSpace();
        int R = inf.readInt(MIN_N, MAX_N, "R");
        assert(1 <= L and L <= R and R <= N);
        inf.readEoln();
  }
  inf.readEof();
}
