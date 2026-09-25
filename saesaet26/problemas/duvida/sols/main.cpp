#include <bits/stdc++.h>

using namespace std;

char letra[2];
char pal[100010];

int main() {
    scanf("%s", letra);
    scanf("%s", pal);
    for (int i=0;pal[i];i++)
        if (pal[i]==letra[0]) {
            printf("%d\n",i+1);
            return 0;
        }
    printf("-1\n");

    return 0;
}
