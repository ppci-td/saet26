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
            printf("eu aposto que voce nao vai digitar todas essas linhas e vai preferir\n");
            printf("copiar e colar ela do PDF da prova, afinal elas sao muito grandes\n");
            printf("nao eh mesmo? Por isso, esta saida eh uma critica.\n");
        }

    }

    return 0;
}
