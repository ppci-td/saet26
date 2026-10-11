#include "rbx.h"
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  int N = inf.readInt(1, 1e5, "N"); inf.readEoln();
  for(int i = 0; i < N; i++){
    if (i) inf.readSpace();
    int M = inf.readLong(1LL, 1e18, "M");
  }
  inf.readEoln();
  inf.readEof();
}
