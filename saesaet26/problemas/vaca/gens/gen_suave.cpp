#include "testlib.h"
#define ll long long int

using namespace std;

ll func(ll a, ll b) {
    ll tot=0;
    for (ll i = a; i<= b; i++)
        tot += __builtin_popcountll(i);
    return tot;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int T = 1000;
    printf("%d\n",T);
    while (T--) {
        ll a, b;
        b = rnd.next(1,1000);
        a = rnd.next(1,(int)b);
        ll f = func(a,b);
        if (rnd.next(1,10) == 1) { // 10% de possivel fail
            if (rnd.next(0,1)==0)
                f++;
            else
                f--;
        }
        printf("%lld %lld\n", b, f);
    }

    return 0;

}
