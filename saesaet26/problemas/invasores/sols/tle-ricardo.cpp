#include <bits/stdc++.h>

using namespace std;

int n, k;
int v[100000];
set<int> S;

int main() {

    scanf("%d %d", &n, &k);
    for (int i=0;i<n;i++)
        scanf("%d", v+i);

    int maior = 1;
    for (int i=0;i<n;i++) {
        S.clear();
        S.insert(v[i]);
        int p = 1;
        while (p < n and (int)S.size() <= k) {
            S.insert(v[(i+p)%n]);
            p++;
            if (S.size() <= k) maior = max(maior, p);
        }
    }
    printf("%d\n",maior);

    return 0;
}
