#include "testlib.h"
#define ll long long int

using namespace std;

ll L;
ll PD[56][2];

ll calc(ll u, ll livre) {
    if (u==-1) return 0;
    if (PD[u][livre] != -1) return PD[u][livre];
    ll opc1=0;
    if (livre==1 or ((L>>u)&1ll)==1)
        opc1 = calc(u-1, 1);
    else
        opc1 = calc(u-1, 0);

    ll opc2=0;
    if (livre==0 and ((L>>u)&1ll)==1)
        opc2 = (L&((1ll<<u)-1ll)) + 1ll + calc(u-1, 0);
    else if (livre==1)
        opc2 = (1ll<<u) + calc(u-1,1);

    return PD[u][livre] = opc1 + opc2;
}

ll total(ll lim) {
    if (lim==0) return 0;
    L = lim;
    memset(PD,0xff,sizeof(PD));
    return calc(55,0);
}

ll func(ll a, ll b) {
    return total(b) - total(a-1);
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int T = 1000;
    printf("%d\n",T);
    while (T--) {
        ll a, b;
        b = rnd.next(1ll,10000000000000000ll);
        a = rnd.next(1ll,b);
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
