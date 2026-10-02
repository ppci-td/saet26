#include <bits/stdc++.h>

using namespace std;

int n, m;
char s[200020];

int main() {

    scanf("%d %d", &n, &m);
    scanf("%s",s);
    for (int i=0;i<m;i++) {
        int l, r;
        scanf("%d %d", &l, &r); l--; r--;
        reverse(s+l,s+r+1);
    }
    printf("%s\n",s);

    return 0;
}
