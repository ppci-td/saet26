#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(1,100000);
    char c = 'a' + rnd.next(0,25);
    printf("%c\n",c);
    for (int i=0;i<n;i++)
        printf("%c", 'a' + rnd.next(0,25));
    printf("\n");

    return 0;
}
