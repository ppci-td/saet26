#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int H = rnd.next(1, 12);
    long long X = rnd.next(1000000000000000000);
    long long Y = rnd.next(1000000000000000000);
    if(X == 0) X++;
    if(Y == 0) Y++;
    cout << H << " " << X << " " << Y << endl;
}