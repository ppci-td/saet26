#include <bits/stdc++.h>

using namespace std;

int n, k, q;
char s[100010];

int calc() {
    int atu=0;
    for (int i=0;s[i];i++)
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
    while (q--) {
        int pos;
        scanf("%d", &pos); pos--;
        if (s[pos]=='o') s[pos] = 'x';
        else s[pos]='o';
        printf("%d\n", calc());
    }

    return 0;
}
