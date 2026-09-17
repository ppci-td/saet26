#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define bazinga ios::sync_with_stdio(false);cin.tie(nullptr);

void solve(){
    string s; ll n, k, q; cin >> n >> k >> q >> s;
    set<ll> st;
    ll seq = 0;
    for(ll i = 0; i < s.size(); i++){
        if(s[i] == 'o') seq++;
        else seq = 0;
        if(seq >= 3) st.insert(i);
    }
    while(q--){
        ll x; cin >> x; x--;
        if(s[x] == 'o'){
            s[x] = 'x';
            if(s[x-1] == 'o' && s[x-2] == 'o') st.erase(x);
            if(s[x-1] == 'o' && s[x+1] == 'o') st.erase(x+1);
            if(s[x+1] == 'o' && s[x+2] == 'o') st.erase(x+2); 
        }
        else{
            s[x] = 'o';
            if(s[x-1] == 'o' && s[x-2] == 'o') st.insert(x);
            if(s[x-1] == 'o' && s[x+1] == 'o') st.insert(x+1);
            if(s[x+1] == 'o' && s[x+2] == 'o') st.insert(x+2); 
        }
        if(st.empty()) cout << -1 << endl;
        else cout << *st.rbegin()+1 << endl;
    }
}
int main(){bazinga; solve(); return 0;}