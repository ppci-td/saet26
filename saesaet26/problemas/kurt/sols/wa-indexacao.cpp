#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define bazinga ios::sync_with_stdio(false);cin.tie(nullptr);

vll fibs;                   
unordered_map<ll,ll> id;  

vll pai, sz;
ll maiorset = 1;

void precomputa(){
  fibs = {1,2};
  while(fibs.back() <= (ll)2e18 / 2){
    ll proximo = fibs[fibs.size()-1] + fibs[fibs.size()-2];
    fibs.pb(proximo);
  }
  for(ll i = 0; i < fibs.size(); i++) id[fibs[i]] = i;
}

void mset(int v){
  pai[v] = v;
  sz[v] = 1;
}

int fset(int v){
  if (v == pai[v]) return v;
  return pai[v] = fset(pai[v]);
}

void uset(int a, int b){
  a = fset(a); b = fset(b);
  if (a != b){
    if(sz[a] < sz[b]) swap(a, b);
    pai[b] = a;
    sz[a] += sz[b];
    maiorset = max(maiorset, sz[a]);
  }
}

vll zeckendorf(ll n){
  vll ans;
  for(ll i = fibs.size()-1; i >= 0; i--){
    if(n >= fibs[i]){
      ans.pb(fibs[i]);
      n -= fibs[i];
    }
  }
  return ans;
}

void solve(){
  precomputa();
  ll tam = fibs.size();
  pai.assign(tam, 0); sz.assign(tam, 0);

  for(ll i = 0; i < tam; i++) mset(i);

  ll n; cin >> n;
  vll v(n), todos;

  for(ll i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  for(ll i = 0; i < n; i++){
    vll cur = zeckendorf(v[i]);


    for(ll j = 0; j < cur.size(); j++){
      ll a = id[cur[j-1]], b = id[cur[j]];
      uset(a, b);
      todos.pb(b);
    }
  }

  cout << maiorset << endl;

  if(maiorset == 1){
    auto it = min_element(todos.begin(), todos.end());
    cout << fibs[*it] << endl;
    return;
  }

  for(ll i = 0; i < tam; i++){
    if(sz[i] == maiorset){
      for(ll j = 0; j < tam; j++){
        if(fset(j) == i) cout << fibs[j] << " ";
      }
      cout << endl;
      return;
    }
  }
}

int main(){bazinga;solve();return 0;}