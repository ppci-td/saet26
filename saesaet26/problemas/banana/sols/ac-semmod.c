#include <stdio.h>

int main() {

    // sem usar mod

    int n, b;
    scanf("%d %d", &n, &b);
    int res=0;
    while (b > 0) {
        b = b-n;
        res++;
    }
    if (b==0)
        printf("%d\n",res);
    else
        printf("-1\n");

    return 0;
}
