#include "testlib.h"

using namespace std;

int n, m;
vector<int> ordem;

void getordem(int ini, int fim) {
    if (ini > fim) return;
    int meio = (ini+fim)/2;
    ordem.push_back(meio);
    getordem(ini,meio-1);
    getordem(meio+1,fim);
}

vector<int> L;
void vai() {
    L.clear();
    for (int i=0;i<n;i++)
        L.push_back(i);
    for (int p=0;p<n/4;p++) {
        if (m==0) break;
        int qro = ordem[p];
        int cade;
        for (int i=p;i<n;i++)
            if (L[i]==qro) {
                cade=i;
                break;
            }
        printf("%d %d\n",p+1,cade+1);
        m--;
        reverse(L.begin()+p,L.begin()+cade+1);
    }
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    n = opt<int>(1);
    m = 100000;
    printf("%d %d\n", n, m);
    for (int i=0;i<n;i++) {
        int tt = rnd.next(0,25);
        printf("%c",'a'+tt);
    }
    printf("\n");
    ordem.clear();
    getordem(0,n-1);
    vai();

    for (int i=0;i<m;i++) {
        int l = rnd.next(1,2);      // força reverse em Omega(N)
        int r = rnd.next(n-1,n);
        if (l > r) swap(l,r);
        printf("%d %d\n",l,r);
    }

    return 0;
}
