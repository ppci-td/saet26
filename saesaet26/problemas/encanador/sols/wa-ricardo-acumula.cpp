#include <bits/stdc++.h>

using namespace std;

char s[100001];

int main() {

    scanf("%s",s);
    bool grande=true;
    int estrela=0;
    for (int i=0;s[i];i++) {
        assert(estrela>=0);
        if (s[i]=='D') {
            if (estrela==0 and !grande) {
                printf("MORTO\n");
                return 0;
            }
            if (estrela==0 and grande) {
                grande=false;
                continue;
            }
            estrela--;
            continue;
        }
        if (s[i]=='C') {
            grande=true;
            if (estrela>0) estrela--;
            continue;
        }
        if (s[i]=='E')
            estrela+=5;
    }
    if (grande)
        printf("ALTO\n");
    else
        printf("BAIXO\n");

    return 0;
}
