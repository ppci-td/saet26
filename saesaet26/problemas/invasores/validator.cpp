#include "rbx.h"
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  
  int N = inf.readInt(1, 100000, "N"); 
  inf.readSpace();
  int K = inf.readInt(1, 100000, "K");
  inf.readEoln();
  for(int i = 0; i < N; i++){
    if (i) inf.readSpace();
    int M = inf.readInt(1, 100000, "M");
  }
  inf.readEoln();
  inf.readEof(); 
}
