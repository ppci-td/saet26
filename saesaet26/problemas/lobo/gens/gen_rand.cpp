#include "testlib.h"

#define ll long long int

using namespace std;

typedef pair<int, int> ii;

set<ii> S;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = 100000 - rnd.next(0,10000);
    int m = rnd.next(0,100000);
    m = min((ll)m, (ll)n*(ll)(n-1)/2ll);

    printf("%d %d\n", n, m);
    S.clear();
    for (int i=0;i<m;i++) {
        int a, b;
        do {
            a = rnd.next(1,n);
            b = rnd.next(1,n);
            if (a > b) swap(a,b);
        } while (S.find(ii(a,b)) != S.end());
        S.insert(ii(a,b));
        if (rnd.next(0,1)==1)
            swap(a,b);
        printf("%d %d\n", a, b);
    }

    int q = 100000 - rnd.next(0,10000);
    printf("%d\n",q);
    while (q--) {
        int a = rnd.next(1,n);
        int b = rnd.next(1,n);
        printf("%d %d\n", a, b);
    }

    return 0;
}
