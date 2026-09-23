#include <bits/stdc++.h>

#define ll long long int

using namespace std;

bool da(ll h,ll n) {

    // horario
    if (n >= h and n%2 == h%2) return true;
    // anti
    if (h >= 12-n and n%2 == h%2) return true;
    return false;
}

int main() {

    ll h, x, y;
    scanf("%lld %lld %lld", &h, &x, &y);
    if (da(h,x) and da(h,y))
        printf("SIM\n");
    else
        printf("NAO\n");


    return 0;
}
