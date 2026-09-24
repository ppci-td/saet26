#include <bits/stdc++.h>

using namespace std;


int main() {

    int n, m, q;
    scanf("%d %d", &n, &m);
    vector<vector<bool> > M(n, vector<bool>(n,false));

    for (int i=0;i<m;i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        M[a][b] = M[b][a] = true;
    }
    for (int i=0;i<n;i++) M[i][i] = true;

    for (int k=0;k<n;k++)
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (M[i][k] and M[k][j])
                    M[i][j]=true;

    scanf("%d", &q);
    while (q--) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        if (M[a][b])
            printf("sim\n");
        else
            printf("nao\n");
    }

    return 0;
}
