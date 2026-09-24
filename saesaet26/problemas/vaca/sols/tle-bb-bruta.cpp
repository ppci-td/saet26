#include <bits/stdc++.h>

#define ll long long int

using namespace std;

ll func(ll a, ll b) {
    ll soma=0;
    for (ll i=a;i<=b;i++)
        soma += __builtin_popcountll(i);
    return soma;
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
