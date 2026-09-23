#include <bits/stdc++.h>

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
            printf("eu aposto que voce nao vai digitar todas essas linhas e vai preferir\n");
            printf("copiar e colar ela do PDF da prova, afinal elas sao muito grandes\n");
            printf("nao eh mesmo? Por isso, esta saida eh uma critica.\n");
        }

    }

    return 0;
}
