#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = 100000 - rnd.next(0,3);
    char c = 'a' + rnd.next(0,25);
    printf("%c\n",c);
    for (int i=0;i<n;i++) {
        char p;
        do {
            p = 'a' + rnd.next(0,25);
        } while (p==c);
        printf("%c", p);
    }
    printf("\n");

    return 0;
}
