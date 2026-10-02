#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n, m;
    n = opt<int>(1);
    m = opt<int>(2);
    printf("%d %d\n", n, m);
    for (int i=0;i<n;i++) {
        int tt = rnd.next(0,25);
        printf("%c",'a'+tt);
    }
    printf("\n");
    for (int i=0;i<m;i++) {
        int l = rnd.next(1,n);
        int r = rnd.next(1,n);
        if (l > r) swap(l,r);
        printf("%d %d\n",l,r);
    }

    return 0;
}
