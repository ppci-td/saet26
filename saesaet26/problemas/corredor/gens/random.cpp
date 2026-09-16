#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(1,100000);
    int k = rnd.next(1,n);
    int q = rnd.next(1,100000);
    printf("%d %d %d\n",n,k,q);
    for (int i=0;i<n;i++)
        printf("%c", "ox"[rnd.next(0,1)]);
    printf("\n");
    while (q--)
        printf("%d\n", rnd.next(1,n));

    return 0;
}
