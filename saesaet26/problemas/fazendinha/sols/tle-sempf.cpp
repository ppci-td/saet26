#include <bits/stdc++.h>

using namespace std;

int n, m, qro;
int M[1024][1024];
int T[2048][2048];

int soma(int x1, int y1, int x2, int y2) {
    int s=0;
    for (int i=x1;i<=x2;i++)
        for (int j=y1;j<=y2;j++)
            s += T[i][j];
    return s;
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

    int menor = 0x3f3f3f3f;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) {
            int r = -1;
            int ini = 0, fim = n+m+1;
            while (ini <= fim) {
                int k = (ini+fim)/2;
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
                    fim = k-1;
                } else
                    ini = k+1;
            }
            if (r != -1)
                menor = min(menor, r);
        }
    if (menor == 0x3f3f3f3f)
        menor = -1;
    cout << menor << endl;

    return 0;
}
