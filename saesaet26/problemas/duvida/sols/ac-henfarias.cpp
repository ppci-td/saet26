#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define bazinga ios::sync_with_stdio(false);cin.tie(nullptr);

void solve(){
    char c; string s; cin >> c >> s;
    for(ll i = 0; i < s.size(); i++){
        if(s[i] == c){
            cout << i+1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main(){bazinga; solve(); return 0;}