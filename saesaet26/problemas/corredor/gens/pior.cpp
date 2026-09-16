#include "testlib.h"

using namespace std;

int L[100000];

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = 100000;
    int k =  10000;
    int q = 100000;
    printf("%d %d %d\n",n,k,q);
    for (int i=0;i<n;i++)
        printf("o");
    printf("\n");

    for (int i=0;i<n;i++)
        L[i] = i+1;

    for (int i=0;i<n;i++) {
        int tt = rnd.next(0,n-i-1);
        swap(L[i],L[i+tt]);
    }

    for (int i=0;i<q;i++)
        printf("%d\n", L[i]);

    return 0;
}
