#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define bazinga ios::sync_with_stdio(false);cin.tie(nullptr);

void solve(){
  string s; cin >> s;
  bool estrela = false;
  ll cur = 2, cnt = 0;
  for(char c : s){
     if(c == 'E'){
      estrela = true;
      cnt = 6;
    }
    if(estrela){
      cnt--;
      if(cnt == 0) estrela = false;
    }
    if(c == 'D'){
      if(estrela) continue;
      cur--;
      if(cur == 0){
        cout << "MORTO" << endl;
        return;
      }
    }
    if(c == 'C') cur = 2;  
  }
  cout << (cur == 1 ? "BAIXO" : "ALTO") << endl;
}
int main(){bazinga; solve(); return 0;}