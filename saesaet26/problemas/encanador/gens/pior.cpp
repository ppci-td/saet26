#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    string S = "";
    for(int i = 0; i < 1e5; i++){
        int N = rnd.next(1,21);
        if(N >= 1 && N <= 15) S.push_back('C');
        if(N >= 16 && N <= 20) S.push_back('E');
        if(N == 21) S.push_back('D');
    }

    cout << S << endl;
}