#include "rbx.h"
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  int H = inf.readInt(1, 12, "H"); inf.readSpace();
  long long X = inf.readLong(1LL, 1e18, "X"); inf.readSpace();
  long long Y = inf.readLong(1LL, 1e18, "Y"); inf.readEoln();
  inf.readEof();
}