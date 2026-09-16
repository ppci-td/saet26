#include "rbx.h"
#include "testlib.h"
#include "assert.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  prepareOpts(argc, argv);

  int MIN_N = getVar<int>("N.min"); // Read from package vars.
  int MAX_N = getVar<int>("N.max");
  int MIN_K = getVar<int>("K.min"); // Read from package vars.
  int MAX_K = getVar<int>("K.max");
  int MIN_Q = getVar<int>("Q.min"); // Read from package vars.
  int MAX_Q = getVar<int>("Q.max");

  int n = inf.readInt(MIN_N, MAX_N, "N");
  inf.readSpace();
  int k = inf.readInt(MIN_K, MAX_K, "K");
  inf.readSpace();
  int q = inf.readInt(MIN_Q, MAX_Q, "Q");
  inf.readEoln();

  assert(k <= n);

  string S = inf.readToken();
  inf.readEoln();

  assert(S.size() == n);
  for (int i=0;i<n;i++)
      assert((S[i]=='o') or (S[i]=='x'));

  while (q--) {
    int pos = inf.readInt(1,n,"pos");
    assert(1 <= pos and pos <= n);
    inf.readEoln();
  }

  inf.readEof();
}
