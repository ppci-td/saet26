#include <bits/stdc++.h>

using namespace std;

int n, m;
int P[200020];

struct nodo {
    int info;  // letra no nodo
    int y;      // x é o indice em s. x é implicito pela posicao na árvore
    int tam;
    bool flag;  // lazy. true se precisa inverter
    nodo *esq, *dir;
    nodo(int l, int yy): info(l), y(yy), tam(1), flag(false), esq(NULL), dir(NULL) {}
};

int gettam(nodo *r) { return (r ? r->tam : 0); }

void upd(nodo *r) {
    if (r) r->tam = 1 + gettam(r->esq) + gettam(r->dir);
}

void unflag(nodo *r) {
    if (r and r->flag) {
        swap(r->esq, r->dir);
        if (r->esq) { r->esq->flag = not r->esq->flag; }
        if (r->dir) { r->dir->flag = not r->dir->flag; }
        r->flag = false;
    }
}

// L = (-inf,x] , R = (x,+inf) // x, se tiver, vai pro L
void split(nodo *r, int offset, int x, nodo *&L, nodo *&R) {
    unflag(r);
    if (r==NULL) { L = R = NULL; return; }
    int mx = offset + gettam(r->esq); // x implicito
    if (x < mx) { split(r->esq, offset, x, L, r->esq); R = r; }
    else { split(r->dir, mx+1, x, r->dir, R); L = r; }
    upd(L); upd(R);
}

// assert que todo x em L < todo y em R
nodo *merge(nodo *L, nodo *R) {
    unflag(L);
    unflag(R);
    if (L==NULL) return R;
    if (R==NULL) return L;
    if (L->y >= R->y) { L->dir = merge(L->dir, R); upd(L); return L; }
    else { R->esq = merge(L, R->esq); upd(R); return R; }
}

// insere repetido se ja tiver x
nodo *insere(nodo *raiz, int letra, int x, int y) {
    unflag(raiz);
    nodo *novo = new nodo(letra,y);
    nodo *L, *R;
    split(raiz, 0, x, L, R);
    return merge(L, merge(novo, R));
}

void libera(nodo *r) {
    if (r==NULL) return;
    libera(r->esq); libera(r->dir); delete r;
}

void inorder(nodo *r) {
    if (r==NULL) return;
    unflag(r);
    inorder(r->esq);
    printf("%d ",r->info+1);
    inorder(r->dir);
}

int main() {

    srand(time(NULL) + clock());

    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++)
        P[i] = i;
    nodo *raiz = NULL;
    for (int i=0;i<n;i++)
        raiz = insere(raiz, P[i], i, rand());

    for (int i=0;i<m;i++) {
        int l, r;
        scanf("%d %d", &l, &r); l--; r--;
        nodo *A, *B, *C, *BC;
        split(raiz, 0, l-1, A, BC);
        split(BC, l, r, B, C);
        unflag(B);
        B->flag = true;
        raiz = merge(A, merge(B,C));
    }

    inorder(raiz);
    printf("\n");

    libera(raiz);
    return 0;
}
