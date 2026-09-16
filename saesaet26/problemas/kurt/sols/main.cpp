#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define bazinga ios::sync_with_stdio(false);cin.tie(nullptr);

vll pai(101), sz(101);
ll maiorset = 1;

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
       if(sz[a] > maiorset){
        maiorset = sz[a];
        //maiorraiz = a;
       }
   }
}

vll zeckendorf(ll n){
  vll fib = {1,2};
  while(fib.back() <= n){
    fib.pb(fib[fib.size()-1]+fib[fib.size()-2]);
  }
  fib.pop_back();

  vll ans;
  for(auto it = fib.rbegin(); it != fib.rend(); it++){
    if(n >= *it){
      ans.pb(*it);
      n -= *it;
    }
  }
  return ans;
}


void solve(){
  ll n; cin >> n;
  vll v(n), todos;
  for(ll i = 1; i <= 100; i++){
    mset(i);
  }
  for(ll i = 0; i < n; i++){
    cin >> v[i];
    vll cur = zeckendorf(v[i]);
    todos.pb(cur[0]);
    for(ll j = 1; j < cur.size(); j++){
      uset(cur[j-1], cur[j]);
      todos.pb(cur[j]);
    }
  }

  // cout << maiorset << endl;
  // for(ll i : todos) cout << i << " "; 
  // cout << endl;

  cout << maiorset << endl;

  if(maiorset == 1LL){
    auto it = min_element(todos.begin(), todos.end())-todos.begin();
    cout << todos[it] << endl;
    return;
  }

  for(ll i = 1; i <= 100; i++){
    if(sz[i] == maiorset){
      for(ll j = 1; j <= 100; j++){
        if(fset(j) == i) cout << j << " ";
      }
      return;
    }
  }  
}
int main(){bazinga; solve(); return 0;}