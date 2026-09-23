#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int N = rnd.next(1,1000);
    int A = rnd.next(1,100);
    int B = N*A;
    cout << N << " " << B << endl;
}