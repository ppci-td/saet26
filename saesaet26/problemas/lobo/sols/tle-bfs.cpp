#include <bits/stdc++.h>

using namespace std;

int n, m, q;
vector<int> adj[100010];
int enf[100010], TT;

int main() {

    memset(enf,0,sizeof(enf));
    TT=0;

    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++) adj[i].clear();
    for (int i=0;i<m;i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%d", &q);
    while (q--) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        TT++;
        queue<int> Q;
        Q.push(a);
        enf[a]=TT;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (auto w : adj[u]) if (enf[w] != TT) {
                Q.push(w);
                enf[w]=TT;
                if (w == b) goto fim;
            }
        }
        fim:;
        if (enf[b]==TT)
            printf("sim\n");
        else
            printf("nao\n");
    }

    return 0;
}
