#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = 1e5;
    int N = n;
    cout << N << endl;
    for(int i = 0; i < N; i++){
        long long M = rnd.next(10000000000000000);
        if(M == 0) M++;
        if (i) cout << " ";
        cout << M;
    }
    cout << endl;
}
