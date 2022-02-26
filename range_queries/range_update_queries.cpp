// cses: Range Update Queries
// tags: segments tree
// huycon

#include <bits/stdc++.h>

typedef long long ll;
const int N = 2e5 + 5;

int a[N];
ll t[4 * N];

void push_lazy(int p) {
    t[p << 1] += t[p];
    t[p << 1 | 1] += t[p];
    t[p] = 0;
}

void build(int p, int l, int r) {
    if (l == r) {
        t[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
}

void update(int p, int l, int r, int i, int j, int v) {
    if (r < i || j < l)
        return;
    if (i <= l && r <= j) {
        t[p] += v;
        return;
    }

    push_lazy(p);

    int mid = (l + r) >> 1;
    update(p << 1, l, mid, i, j, v);
    update(p << 1 | 1, mid + 1, r, i, j, v);
}

ll get(int p, int l, int r, int i) {
    if (i < l || r < i)
        return -1;
    if (l == i && i == r)
        return t[p];

    push_lazy(p);

    int mid = (l + r) >> 1;
    ll x = get(p << 1, l, mid, i);
    return x != -1 ? x : get(p << 1 | 1, mid + 1, r, i);
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);

    build(1, 1, n);

    while (q--) {
        int k;
        scanf("%d", &k);
        if (k == 1) {
            int l, r;
            scanf("%d%d%d", &l, &r, &k);
            update(1, 1, n, l, r, k);
        }
        else {
            scanf("%d", &k);
            printf("%lld\n", get(1, 1, n, k));
        }
    }
}
