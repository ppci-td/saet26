#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// F(N): numero total de bits 1 em todos os inteiros de 0 a N
ll F(ll N) {
    if (N <= 0) return 0;
    int n = 64 - __builtin_clzll(N);          // numero de bits de N
    // dp[b+1][l]: estado "escrevendo o bit b"; dp[0][*] = 0 (nada mais a escrever)
    vector<array<ll, 2>> dp(n + 1);
    dp[0] = {0, 0};
    for (int b = 0; b < n; b++) {
        int Nb = (N >> b) & 1;
        ll R = N & ((1LL << b) - 1);          // N_{b-1}...N_0
        for (int l = 0; l < 2; l++) {
            ll val = 0;
            // escrever bit 0
            int l2 = (l == 1 && Nb == 0) ? 1 : 0;
            val += dp[b][l2];
            // escrever bit 1
            if (l == 0) val += (1LL << b) + dp[b][0];
            else if (Nb == 1) val += R + 1 + dp[b][1];
            dp[b + 1][l] = val;
        }
    }
    return dp[n][1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll B, f;
        cin >> B >> f;
        ll FB = F(B);
        auto cnt = [&](ll a) { return FB - F(a - 1); };   // f(a, B)
        // f(a,B) e estritamente decrescente em a: menor a com f(a,B) <= f
        ll lo = 1, hi = B + 1;
        while (lo < hi) {
            ll mid = (lo + hi) / 2;
            if (cnt(mid) <= f) hi = mid;
            else lo = mid + 1;
        }
        if (lo <= B && cnt(lo) == f) cout << lo << '\n';
        else {
            cout << "Eu aposto que voce nao vai digitar todas\n";
            cout << "essas linhas e vai copiar e colar do PDF.\n";
            cout << "Por isso, esta saida eh uma critica.\n";
        }
    }
}