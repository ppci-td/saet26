#include <bits/stdc++.h>

using namespace std;

int n, k, q;
char s[100010];

int calc(int primeiro, int ultimo) {
    int atu=0;
    for (int i=primeiro;i<=ultimo;i++)
        if (s[i]=='o') {
            atu++;
            if (atu >= k) return i+1;
        } else
            atu=0;
    return -1;
}

int main() {
    scanf("%d %d %d", &n, &k, &q);
    scanf("%s", s);
    int prim=n, ult=-1;
    for (int i=0;i<n;i++)
        if (s[i]=='o') {
            prim=i;
            break;
        }
    for (int i=n-1;i>=0;i--) {
        if (s[i]=='o') {
            ult=i;
            break;
        }
    }

    while (q--) {
        int pos;
        scanf("%d", &pos); pos--;
        if (s[pos]=='o') {
            s[pos] = 'x';
            while (prim<n and s[prim]=='x') prim++;
            while (ult>=0 and s[ult]=='x') ult--;
        }
        else {
            s[pos]='o';
            if (pos < prim) prim = pos;
            if (pos > ult) ult = pos;
        }
        printf("%d\n", calc(prim, ult));
    }

    return 0;
}
