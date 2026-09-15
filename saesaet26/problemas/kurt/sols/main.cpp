#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define bazinga ios::sync_with_stdio(false);cin.tie(nullptr);

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


}
int main(){bazinga; solve(); return 0;}