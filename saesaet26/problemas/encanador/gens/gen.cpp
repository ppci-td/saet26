#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    string S = "";
    for(int i = 0; i < 1e5; i++){
        int N = rnd.next(1,3);
        if(N == 1) S.push_back('C');
        if(N == 2) S.push_back('E');
        if(N == 3) S.push_back('D');
    }

    cout << S << endl;
}