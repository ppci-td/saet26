#include <bits/stdc++.h>

using namespace std;

int n, m, q;
vector<int> adj[100010];
bool enf[100010];
int cc[100010];

int main() {

    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++) adj[i].clear();
    for (int i=0;i<m;i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(enf,false,sizeof(enf));
    int C=0;
    for (int i=0;i<n;i++) if (!enf[i]) {
        queue<int> Q;
        Q.push(i);
        enf[i]=true;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            cc[u] = C;
            for (auto w : adj[u]) if (!enf[w]) {
                Q.push(w);
                enf[w]=true;
            }
        }
        C++;
    }
    scanf("%d", &q);
    while (q--) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        if (cc[a] == cc[b])
            printf("sim\n");
        else
            printf("nao\n");
    }

    return 0;
}
