#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {

    int T;
    for(scanf("%d",&T);T--;) {
        ll b, f;
        scanf("%lld %lld", &b, &f);
        ll catu = __builtin_popcountll(b), atu = b;
        while (catu < f and atu > 0) {
            atu--;
            catu += __builtin_popcountll(atu);
        }
        if (catu == f)
            printf("%lld\n", atu);
        else {
            printf("Eu aposto que voce nao vai digitar todas\n");
            printf("essas linhas e vai copiar e colar do PDF.\n");
            printf("Por isso, esta saida eh uma critica.\n");
        }
    }

    return 0;
}
