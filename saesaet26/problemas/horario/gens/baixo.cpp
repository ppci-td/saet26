#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int H = rnd.next(1, 12);
    int X = rnd.next(1, 10);
    int Y = rnd.next(1, 10);
    cout << H << " " << X << " " << Y << endl;
}