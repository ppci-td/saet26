#include "rbx.h"
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  
  int N = inf.readInt(1, 100000, "N"); inf.readSpace();
  int B = inf.readInt(N, 100000, "B"); inf.readEoln();
  inf.readEof();
}