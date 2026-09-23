#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int N = rnd.next(1,100000);
    int B = rnd.next(N,100000);
    cout << N << " " << B << endl;
}