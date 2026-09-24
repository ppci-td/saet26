#include "testlib.h"

using namespace std;

typedef pair<int, int> ii;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = 100000;
    int m = n-2;

    printf("%d %d\n", n, m);

    for (int i=1;i<n/2;i++)
        printf("%d %d\n",i,i+1);
    for (int i=n/2+1;i<n;i++)
        printf("%d %d\n",i,i+1);

    int q = 100000;
    printf("%d\n",q);
    while (q--) {
        int a = rnd.next(1,n);
        int b = rnd.next(1,n);
        printf("%d %d\n", a, b);
    }

    return 0;
}
