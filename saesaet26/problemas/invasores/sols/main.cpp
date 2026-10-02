#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define bazinga ios::sync_with_stdio(false);cin.tie(nullptr);

void solve(){
  ll n, k; cin >> n >> k;
  vll v(n); for(ll &i : v) cin >> i;
  
  for(ll i = 0; i <= n; i++){
    v.pb(v[i]);
  }

  vll cnt (n,0) ;
  ll num = 0, esq = 0, ans = 0;

  auto add = [&](ll x){
      cnt[x]++;
      if(cnt[x] == 1) num++;
  };

  auto remove = [&](ll x){
    cnt[x]--;
    if(cnt[x] == 0) num--;
  };

  auto bom = [&](){
    return num <= k;
  };

  for(ll dir = 0; dir < v.size(); dir ++){
    add(v[dir]);
    while(!bom()){
      remove(v[esq]);
      esq++;
    }
  ans = max(ans,dir-esq+1);
  }
  cout << (ans > n ? n : ans) << endl;
}
int main(){bazinga; solve(); return 0;}