#include <bits/stdc++.h>

using namespace std;

int n, m, qro;
int M[2048][2048];

int soma(int l, int c, int r) {
    int s=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (abs(i-l) + abs(j-c) <= r)
                s += M[i][j];
    return s;
}

int main() {

    cin >> n >> m >> qro;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin >> M[i][j];

    int menor = 0x3f3f3f3f;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) {
            int r = -1;
            for (int k=0;k<n+m;k++) {
                int tt = soma(i,j,k);
                if (tt >= qro) {
//                    cout << i << "," << j << ": r = " << k << ", tot = " << tt << endl;
                    r=k;
                    break;
                }
            }
            if (r != -1)
                menor = min(menor, r);
        }
    if (menor == 0x3f3f3f3f)
        menor = -1;
    cout << menor << endl;

    return 0;
}
