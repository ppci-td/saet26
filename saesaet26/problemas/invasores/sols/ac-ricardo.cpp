#include <bits/stdc++.h>

using namespace std;

int n, k;
int v[200000];
set<int> S;
multiset<int> MS;

int main() {

    scanf("%d %d", &n, &k);
    for (int i=0;i<n;i++)
        scanf("%d", v+i);

    for (int i=n;i<2*n;i++)
        v[i] = v[i-n];

    int maior = 1;
    S.clear();
    MS.clear();
    S.insert(v[0]);
    MS.insert(v[0]);
    int j=0;
    for (int i=0;i<2*n;i++) {
        while (j+1<2*n and j-i+1 < n and !(S.size() == k and S.find(v[j+1]) == S.end())) {
            j++;
            S.insert(v[j]);
            MS.insert(v[j]);
        }
        maior = max(maior, j-i+1);
        MS.erase(MS.lower_bound(v[i]));
        if (MS.find(v[i]) == MS.end())
            S.erase(v[i]);
    }
    printf("%d\n",maior);

    return 0;
}
