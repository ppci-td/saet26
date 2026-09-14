#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int A = rnd.next(1,6);
    int G = rnd.next(1,6);
    cout << A << " " << G << endl;
}