#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int L[MAXN], R[MAXN], sz[MAXN], val[MAXN];
unsigned pri[MAXN];
bool rev_[MAXN];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline void upd(int t) { sz[t] = 1 + sz[L[t]] + sz[R[t]]; }

inline void push(int t) {
    if (rev_[t]) {
        swap(L[t], R[t]);
        if (L[t]) rev_[L[t]] ^= 1;
        if (R[t]) rev_[R[t]] ^= 1;
        rev_[t] = false;
    }
}

// separa os k primeiros elementos em l, o resto em r
void split(int t, int k, int &l, int &r) {
    if (!t) { l = r = 0; return; }
    push(t);
    if (sz[L[t]] < k) {
        split(R[t], k - sz[L[t]] - 1, R[t], r);
        l = t;
    } else {
        split(L[t], k, l, L[t]);
        r = t;
    }
    upd(t);
}

int merge(int a, int b) {
    if (!a || !b) return a ? a : b;
    if (pri[a] > pri[b]) {
        push(a);
        R[a] = merge(R[a], b);
        upd(a);
        return a;
    } else {
        push(b);
        L[b] = merge(a, L[b]);
        upd(b);
        return b;
    }
}

vector<int> out;
void inorder(int t) {
    if (!t) return;
    push(t);
    inorder(L[t]);
    out.push_back(val[t]);
    inorder(R[t]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    int root = 0;
    for (int i = 1; i <= N; i++) {
        val[i] = i; sz[i] = 1; pri[i] = rng();
        root = merge(root, i);
    }
    while (M--) {
        int l, r;
        cin >> l >> r;
        int a, b, c;
        split(root, l - 1, a, b);       // A: posicoes < l
        split(b, r - l + 1, b, c);      // B: [l, r], C: > r
        if (b) rev_[b] ^= 1;
        root = merge(merge(a, b), c);
    }
    inorder(root);
    for (int i = 0; i < N; i++) cout << out[i] << (i + 1 < N ? ' ' : '\n');
}