#include "rbx.h"
#include "testlib.h"
#include "assert.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  prepareOpts(argc, argv);

  int MIN_N = getVar<int>("N.min"); // Read from package vars.
  int MAX_N = getVar<int>("N.max");

  string letra = inf.readToken();
  assert(letra.size() == 1);
  assert('a' <= letra[0] and letra[0] <= 'z');
  inf.readEoln();
  string pal = inf.readToken();
  assert(pal.size() >= MIN_N and pal.size() <= MAX_N);
  int n = pal.size();
  for (int i=0;i<n;i++)
      assert('a' <= pal[i] and pal[i] <= 'z');
  inf.readEoln();
  inf.readEof();
}
