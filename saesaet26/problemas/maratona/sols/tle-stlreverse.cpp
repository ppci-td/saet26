#include <bits/stdc++.h>

using namespace std;

int n, m;
int P[200020];

int main() {

    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++)
        P[i] = i;
    for (int i=0;i<m;i++) {
        int l, r;
        scanf("%d %d", &l, &r); l--; r--;
        reverse(P+l,P+r+1);
    }
    for (int i=0;i<n;i++)
        printf("%d ", P[i]+1);
    printf("\n");

    return 0;
}
