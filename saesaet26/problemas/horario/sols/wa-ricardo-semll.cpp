#include <bits/stdc++.h>

using namespace std;

bool da(int h, int n) {

    // horario
    if (n >= h and n%2 == h%2) return true;
    // anti
    if (h >= 12-n and n%2 == h%2) return true;
    return false;
}

int main() {

    int h, x, y;
    scanf("%d %d %d", &h, &x, &y);
    if (da(h,x) and da(h,y))
        printf("SIM\n");
    else
        printf("NAO\n");


    return 0;
}
