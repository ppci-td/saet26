#include <bits/stdc++.h>

using namespace std;

int n, m, q;
vector<int> adj[100010];
bool vis[100010];
int cc[100010];

void dfs(int u, int c) {
    vis[u]=true;
    cc[u] = c;
    for (auto w : adj[u])
        if (!vis[w])
            dfs(w,c);
}

int main() {

    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++) adj[i].clear();
    for (int i=0;i<m;i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    int C=0;
    for (int i=0;i<n;i++) if (!vis[i])
        dfs(i,C++);
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
