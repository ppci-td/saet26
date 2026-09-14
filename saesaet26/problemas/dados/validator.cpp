#include "rbx.h"
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  int A = inf.readInt(1, 6, "A"); inf.readSpace();
  int G = inf.readInt(1, 6, "G"); inf.readEoln();
  inf.readEof();
}