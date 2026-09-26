#include <bits/stdc++.h>

using namespace std;

int n, m, qro;
int M[1024][1024];
int T[2048][2048];
int F[2048][2048];

int soma(int x1, int y1, int x2, int y2) {
    return F[x2][y2] - (x1?F[x1-1][y2]:0) - (y1?F[x2][y1-1]:0) + ((x1 and y1)?F[x1-1][y1-1]:0);
}

int main() {

    cin >> n >> m >> qro;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin >> M[i][j];

    memset(T,0,sizeof(T));
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            T[i+j][j-i+1024] = M[i][j];

    for (int i=0;i<2048;i++)
        for (int j=0;j<2048;j++)
            F[i][j] = T[i][j] + (j?F[i][j-1]:0) + (i?F[i-1][j]:0) - ((i and j)?F[i-1][j-1]:0);

    int menor = 0x3f3f3f3f;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) {
            int r = -1;
            for (int k=0;k<n+m;k++) {
                int x1 = i+j-k;
                int y1 = j-k-i + 1024;
                int x2 = i+j+k;
                int y2 = j+k-i + 1024;
                x1 = min(x1,2047);  // just in case
                x1 = max(0,x1);
                y1 = min(y1,2047);
                y1 = max(0,y1);
                x2 = min(x2,2047);
                x2 = max(0,x2);
                y2 = min(y2,2047);
                y2 = max(0,y2);
                int tt = soma(x1,y1,x2,y2);
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
