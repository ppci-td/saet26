#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define bazinga ios::sync_with_stdio(false);cin.tie(nullptr);

vll pai(1e5), sz(1e5);
void mset(ll v){
   pai[v] = v;
   sz[v] = 1;
}

ll fset(ll v){
   if(v == pai[v]) return v;
   return pai[v] = fset(pai[v]);
}

void uset(ll a, ll b){
   a = fset(a); b = fset(b);
   if(a != b){
       if(sz[a] < sz[b]) swap(a, b);
       pai[b] = a;
       sz[a] += sz[b];
   }
}

void solve(){
    ll n, m; cin >> n >> m;
    for(ll i = 1; i <= n; i++) mset(i);
    for(ll i = 0; i < m; i++){
        ll x, y; cin >> x >> y;
        uset(x, y);
    }
    ll q; cin >> q;
    while(q--){
        ll a, b; cin >> a >> b;
        cout << (fset(a) == fset(b) ? "sim" : "nao") << endl;
    }
}

int main(){bazinga; solve(); return 0;}