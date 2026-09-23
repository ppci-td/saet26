#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int H = rnd.next(1, 12);
    long long X = 1e18;
    long long Y = 1e18;
    cout << H << " " << X << " " << Y << endl;
}