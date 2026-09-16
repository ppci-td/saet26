#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, k, q;
char s[100001];
set<ii> S;
set<ii> vale;

int main() {
    scanf("%d %d %d", &n, &k, &q);
    scanf("%s", s);
    assert(strlen(s) == n);
    S.clear();
    int ini=-1;
    for (int i=0;i<n;i++) {
        if (s[i]=='x') {
            if (i>0 and s[i-1]=='o')
                S.insert(ii(ini,i-1));
            ini = -1;
        } else if (ini==-1)
            ini=i;
    }
    if (ini != -1)
        S.insert(ii(ini, n-1));

    vale.clear();
    for (auto w : S)
        if (w.second - w.first + 1 >= k)
            vale.insert(w);

    while (q--) {
        int pos;
        scanf("%d", &pos); pos--;
        if (s[pos]=='x') {
            // x --> o
            if ((pos==0 or s[pos-1]=='x') and (pos==n-1 or s[pos+1]=='x') ) {
                // x[o]x
                S.insert(ii(pos,pos));
                if (k==1)
                    vale.insert(ii(pos,pos));
            } else if ((pos==0 or s[pos-1]=='x') and (pos < n-1 and s[pos+1]=='o') ) {
                // x[o]o
                ii seg = *(S.lower_bound(ii(pos+1,-1)));
                S.erase(seg);
                vale.erase(seg);
                seg.first--;
                S.insert(seg);
                if (seg.second - seg.first + 1 >= k)
                    vale.insert(seg);
            } else if ((pos > 0 and s[pos-1]=='o') and (pos == n-1 or s[pos+1]=='x') ) {
                // o[o]x
                auto Si = S.lower_bound(ii(pos+1,-1)); Si--;
                ii seg = *Si;
                S.erase(seg);
                vale.erase(seg);
                seg.second++;
                S.insert(seg);
                if (seg.second - seg.first + 1 >= k)
                    vale.insert(seg);
            } else {
                // o[o]o
                auto Sir = S.lower_bound(ii(pos+1,-1));
                auto Sil = Sir; Sil--;
                ii segr = *Sir;
                ii segl = *Sil;
                S.erase(segr);
                S.erase(segl);
                vale.erase(segr);
                vale.erase(segl);
                ii seg = ii(segl.first, segr.second);
                S.insert(seg);
                if (seg.second - seg.first + 1 >= k)
                    vale.insert(seg);
            }
            s[pos]='o';
        } else {
            // o --> x
            if ((pos==0 or s[pos-1]=='x') and (pos==n-1 or s[pos+1]=='x') ) {
                // x[x]x
                S.erase(ii(pos,pos));
                vale.erase(ii(pos,pos));
            } else if ((pos==0 or s[pos-1]=='x') and (pos < n-1 and s[pos+1]=='o') ) {
                // x[x]o
                ii seg = *(S.lower_bound(ii(pos,-1)));
                S.erase(seg);
                vale.erase(seg);
                seg.first++;
                S.insert(seg);
                if (seg.second - seg.first + 1 >= k)
                    vale.insert(seg);
            } else if ((pos > 0 and s[pos-1]=='o') and (pos == n-1 or s[pos+1]=='x') ) {
                // o[x]x
                auto Si = S.lower_bound(ii(pos+1,-1)); Si--;
                ii seg = *Si;
                S.erase(seg);
                vale.erase(seg);
                seg.second--;
                S.insert(seg);
                if (seg.second - seg.first + 1 >= k)
                    vale.insert(seg);
            } else {
                // o[x]o
                auto Si = S.lower_bound(ii(pos+1,-1)); Si--;
                ii seg = *Si;
                S.erase(seg);
                vale.erase(seg);
                ii seg1 = ii(seg.first,pos-1);
                ii seg2 = ii(pos+1,seg.second);
                S.insert(seg1);
                S.insert(seg2);
                if (seg1.second - seg1.first + 1 >= k)
                    vale.insert(seg1);
                if (seg2.second - seg2.first + 1 >= k)
                    vale.insert(seg2);
            }

            s[pos]='x';
        }
        if (vale.empty())
            printf("-1\n");
        else
            printf("%d\n", vale.begin()->first + k );
    }

    return 0;
}
