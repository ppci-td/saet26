#include <bits/stdc++.h>

using namespace std;

int n, m, q;
vector<int> adj[100010];
int vis[100010], TT;

bool dfs(int a, int b) {
    if (a==b) return true;
    vis[a]=TT;
    for (auto w : adj[a])
        if (vis[w] != TT)
            if (dfs(w,b))
                return true;
    return false;
}

int main() {

    memset(vis,0,sizeof(vis));
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
        if (dfs(a,b))
            printf("sim\n");
        else
            printf("nao\n");
    }

    return 0;
}
