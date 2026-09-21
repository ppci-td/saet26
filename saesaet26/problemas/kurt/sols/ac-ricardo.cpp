#include <bits/stdc++.h>

#define ll long long int

using namespace std;

typedef pair<ll,ll> ii;

vector<ll> fib;
ll F, n;
ll pai[100110];
ll tamcc[100110];

ll getpai(ll u) { return u==pai[u] ? u : pai[u]=getpai(pai[u]); }

int main() {

    ll pen = 0, ult = 1;
    fib.clear();
    while (ult <= 1000000000000000000ll) {
        fib.push_back(ult);
        ll prox = pen+ult;
        pen = ult;
        ult = prox;
    }

    F = (ll)fib.size(); // 87
    /*printf("%lld\n", (ll)fib.size());
    for (auto w : fib)
        printf("%lld ", w);*/

    cin >> n;
    for (ll i=0;i<n+F;i++) pai[i] = i;
    ll menornum = 0x3f3f3f3f3f3f3f3fll;
    for (ll i=0;i<n;i++) {
        ll num;
        cin >> num;
        menornum = min(num, menornum);
        while (num > 0) {
            ll pos = lower_bound(fib.begin(),fib.end(),num) - fib.begin();
            if (pos == F or fib[pos] != num) pos--;
            num -= fib[pos];
            ll pa = getpai(pos);
            ll pb = getpai(F+i);
            if (pa == pb) continue;
            pai[pa] = pb;
        }
    }

    memset(tamcc,0,sizeof(tamcc));
    ll maior = 0;
    for (ll i=0;i<F;i++) {
        ll cc = getpai(i);
        tamcc[cc]++;
        maior = max(maior, tamcc[cc]);
    }

    cout << maior << endl;
    if (maior == 1) {
        // xunxo
        cout << menornum << endl;
        return 0;
    }
    ll printar = -1;
    for (ll i=0;i<F;i++)
        if (tamcc[getpai(i)]==maior) {
            printar = getpai(i);
            break;
        }
    for (ll i=0;i<F;i++)
        if (getpai(i) == printar)
            cout << fib[i] << " ";
    cout << endl;

    return 0;
}
