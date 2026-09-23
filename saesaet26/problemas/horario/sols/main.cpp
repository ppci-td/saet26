#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define bazinga ios::sync_with_stdio(false);cin.tie(nullptr);

void solve(){
    ll h, x, y; cin >> h >> x >> y;
    bool a = false, b = false;
    if((x&1) == (h&1)){
      if(h <= x || x >= 12-h) a = true;
    }
    if((y&1) == (h&1)){
      if(h <= y || y >= 12-h) b = true;
    }
    cout << (a && b ? "SIM" : "NAO") << endl;
}
int main(){bazinga; solve(); return 0;}