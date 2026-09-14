#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define bazinga ios::sync_with_stdio(false);cin.tie(nullptr);

void solve(){
    ll a, g; cin >> a >> g;
    if(a < g) cout << "Andre ficou com a laranja";
    else if(a > g) cout << "Gabriel ficou com a laranja";
    else cout << (a&1 == 0 ? "Andre ficou com a laranja" : "Gabriel ficou com a laranja");
    cout << endl;
}
int main(){bazinga; solve(); return 0;}