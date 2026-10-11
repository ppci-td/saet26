#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define bazinga ios::sync_with_stdio(false);cin.tie(nullptr);

void solve(){
    ll n, k, q; string s; cin >> n >> k >> q >> s;
    set<pair<ll,ll>> validos, acertos;
    
    bool acerto = false;
    ll cnt = 0, cur;
    for(ll i = 0; i < (ll)s.size(); i++){
        if(s[i] == 'o'){
            if(!acerto) cur = i;
            acerto = true;
            cnt++;
        }
        if(s[i] == 'x' && acerto){
            acertos.insert({cur,i-1});
            if(cnt >= k) validos.insert({cur,i-1});
            acerto = false;
            cnt = 0;
        }
    }
    while(q--){
        ll x; cin >> x;
        
    }

}
int main(){bazinga; solve(); return 0;}