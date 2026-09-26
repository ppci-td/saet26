#include "testlib.h"

using namespace std;

int M[1024][1024];

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = 1000;
    int m = 1000;
    int soma=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) {
            M[i][j] = rnd.next(0,9);
            soma += M[i][j];
        }
    int t = rnd.next((90*soma)/100, soma);

    printf("%d %d %d\n",n,m,t);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (j) printf(" ");
            printf("%d", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}
