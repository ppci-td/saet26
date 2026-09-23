#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define bazinga ios::sync_with_stdio(false);cin.tie(nullptr);

void solve(){
  ll n, b; cin >> n >> b;
  cout << (n == b ? n/b : -1) << endl;
}
int main(){bazinga; solve(); return 0;}