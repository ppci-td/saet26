#include "rbx.h"
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  prepareOpts(argc, argv);

  int MIN_T = getVar<int>("T.min"); // Read from package vars.
  int MAX_T = getVar<int>("T.max");

  int T = inf.readInt(MIN_T, MAX_T, "T");
  inf.readEoln();
  while (T--) {
    inf.readLong(1ll, 10000000000000000ll, "B");
    inf.readSpace();
    inf.readLong(0ll, 1000000000000000000ll, "F");
    inf.readEoln();
  }
  inf.readEof();
}
