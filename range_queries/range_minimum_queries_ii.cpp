// cses: Range Minimum Queries II
// tags: segment tree
// huycon

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int t[4 * N], a[N];

void build(int p, int l, int r) {
    if (l > r)
        return;
    if (l == r) {
        t[p] = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(2 * p, l, mid);
    build(2*p + 1, mid + 1, r);

    t[p] = min(t[2 * p], t[2*p + 1]);
}

void update(int p, int l, int r, int i, int v) {
    if (r < i || i < l)
        return;
    if (l == i && i == r) {
        t[p] = v;
        return;
    }

    int mid = (l + r) >> 1;
    update(2 * p, l, mid, i, v);
    update(2*p + 1, mid + 1, r, i, v);

    t[p] = min(t[2 * p], t[2*p + 1]);
}

int get(int p, int l, int r, int i, int j) {
    if (r < i || j < l)
        return 0x3f3f3f3f;
    if (i <= l && r <= j)
        return t[p];

    int mid = (l + r) >> 1;
    return min(get(2 * p, l, mid, i, j), get(2*p + 1, mid + 1, r, i, j));
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);

    memset(t, 0x3f, 4 * n * sizeof(t[0]));

    build(1, 1, n);

    while (q--) {
        int k, a, b;
        scanf("%d%d%d", &k, &a, &b);
        if (k == 1)
            update(1, 1, n, a, b);
        else
            printf("%d\n", get(1, 1, n, a, b));
    }
}
