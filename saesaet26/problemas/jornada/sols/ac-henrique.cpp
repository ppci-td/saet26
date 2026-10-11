#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define vll vector<ll>
#define bazinga ios::sync_with_stdio(false);cin.tie(nullptr);

void solve(){
    ld h0, x1, y1, x2, y2, d1, d2; cin >> h0 >> x1 >> y1 >> x2 >> y2 >> d1 >> d2;
    ld c = h0;
    ld r1 = y1-c, r2 = y2-c;
    ld det = x1*x1*x2 - x2*x2*x1;
    ld a = (r1*x2 - r2*x1)/det;
    ld bc = (x1*x1*r2 - x2*x2*r1)/det;
    ld ans = a*d1*d1*d1/3 + bc*d1*d1/2 + c*d1;
    ld ans2 = a*d2*d2*d2/3 + bc*d2*d2/2 + c*d2;
    cout << fixed << setprecision(10) << ans2-ans << endl;
}
int main(){bazinga;ll t;cin>>t;while(t--) solve();return 0;}