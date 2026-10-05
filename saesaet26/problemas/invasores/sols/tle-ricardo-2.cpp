#include <bits/stdc++.h>

using namespace std;

int n, k, difs;
int v[100000];
int qts[100010];
int ts[100010], TS;

inline void add(int u) {
    if (ts[u] != TS) {
        ts[u]=TS;
        qts[u]=0;
        difs++;
    }
    qts[u]++;
}

int main() {

    memset(ts,0,sizeof(ts)); TS=0;

    scanf("%d %d", &n, &k);
    for (int i=0;i<n;i++)
        scanf("%d", v+i);

    int maior = 1;
    for (int i=0;i<n;i++) {
        TS++;
        add(v[i]);
        int p = 1;
        difs = 1;
        while (p < n and difs <= k) {
            add(v[(i+p)%n]);
            p++;
            if (difs <= k) maior = max(maior, p);
        }
    }
    printf("%d\n",maior);

    return 0;
}
