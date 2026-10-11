#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define bazinga ios::sync_with_stdio(false);cin.tie(nullptr);

void solve(){
    ll n, k, q; string s; cin >> n >> k >> q >> s;
    set<pair<ll,ll>> validos, acertos;

    auto add = [&](ll l, ll r){
        acertos.insert({l, r});
        if(r-l+1 >= k) validos.insert({l, r});
    };
    auto rem = [&](ll l, ll r){
        acertos.erase({l, r});
        if(r-l+1 >= k) validos.erase({l, r});
    };

    bool acerto = false;
    ll cur = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] == 'o'){
            if(!acerto) cur = i;
            acerto = true;
        } else if(acerto){
            add(cur, i-1);
            acerto = false;
        }
    }
    if(acerto) add(cur, n-1);

    while(q--){
        ll x; cin >> x; x--;
        if(s[x] == 'o'){
            auto it = prev(acertos.upper_bound({x, LLONG_MAX}));
            ll l = it->first, r = it->second;
            rem(l, r);
            if(l <= x - 1) add(l, x - 1);
            if(x + 1 <= r) add(x + 1, r);
            s[x] = 'x';
        } else {
            ll l = x, r = x;
            if(x > 0 && s[x-1] == 'o'){
                auto it = prev(acertos.upper_bound({x-1, LLONG_MAX}));
                l = it->first;
                rem(it->first, it->second);
            }
            if(x+1 < n && s[x+1] == 'o'){
                auto it = acertos.lower_bound({x+1, LLONG_MIN});
                r = it->second;
                rem(it->first, it->second);
            }
            add(l, r);
            s[x] = 'o';
        }

        if(validos.empty()) cout << -1 << endl;
        else cout << validos.begin()->first+k << endl;
    }
}
int main(){bazinga; solve(); return 0;}