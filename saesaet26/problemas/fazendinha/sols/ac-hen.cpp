#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define bazinga ios::sync_with_stdio(false);cin.tie(nullptr);

ll soma(const vector<vll> &p, ll w, ll u1, ll v1, ll u2, ll v2){
    u1 = max(u1, 1LL); v1 = max(v1, 1LL);
    u2 = min(u2, w); v2 = min(v2, w);
    if(u1 > u2 || v1 > v2) return 0;
    return p[u2][v2]-p[u1-1][v2] - p[u2][v1-1] + p[u1-1][v1-1];
}

void solve(){
    ll n, m, t; cin >> n >> m >> t;
    ll w = n+m;
    vector<vll> psum(w+1, vll(w+1, 0));

    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            ll b; cin >> b;
            psum[i+j][j-i+n] += b;
        }
    }


    for(ll i = 1; i <= w; i++)
        for(ll j = 1; j <= w; j++)
            psum[i][j] += psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];

    if(psum[w][w] < t){
        cout << -1 << endl;
        return;
    }

    ll melhor = w; 
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            ll u0 = i+j, v0 = j-i+n;
            ll esq = 0, dir = melhor; 
            while(esq < dir){
                ll mid = (esq+dir) / 2;
                if(soma(psum, w, u0 - mid, v0 - mid, u0 + mid, v0 + mid) >= t) dir = mid;
                else esq = mid + 1;
            }
            melhor = min(melhor, esq);
        }
    }
    cout << melhor << endl;
}
int main(){bazinga; solve(); return 0;}