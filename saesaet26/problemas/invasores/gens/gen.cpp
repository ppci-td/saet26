#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = rnd.next(1, 100000);
    int K = rnd.next(1, 100000);
    cout << N << " " << K << endl;
    for(int i = 0; i < N; i++){
        int M = rnd.next(1, 100000);
        cout << M;
        if(i != N-1) cout << " ";
    }
    cout << endl;
}