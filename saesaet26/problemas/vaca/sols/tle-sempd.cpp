#include <bits/stdc++.h>

#define ll long long int

using namespace std;

ll L;

ll calc(ll u, ll livre) {
    if (u==-1) return 0;

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

    return opc1 + opc2;
}

ll total(ll lim) {
    if (lim==0) return 0;
    L = lim;
    return calc(55,0);
}

ll func(ll a, ll b) {
    return total(b) - total(a-1);
}

int main() {

    int T;
    for(scanf("%d",&T);T--;) {
        ll b, f;
        scanf("%lld %lld", &b, &f);

        ll ini = 1, fim = b, resp = -1;
        while (ini <= fim) {
            ll meio = (ini+fim)/2;
            ll ff = func(meio,b);
            if (ff == f) {
                resp = meio;
                break;
            }
            if (ff < f)
                fim = meio-1;
            else
                ini = meio+1;
        }
        if (resp != -1)
            printf("%lld\n", resp);
        else {
            printf("Eu aposto que voce nao vai digitar todas\n");
            printf("essas linhas e vai copiar e colar do PDF.\n");
            printf("Por isso, esta saida eh uma critica.\n");
        }

    }

    return 0;
}
