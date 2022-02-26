// cses: Range Xor Queries
// tags: bit
// huycon

#include <bits/stdc++.h>

const int N = 2e5 + 5;
int n, bit[N];

void update(int i, int v) {
    while (i <= n) {
        bit[i] ^= v;
        i += i & -i;
    }
}

int get(int i) {
    int res = 0;
    while (i > 0) {
        res ^= bit[i];
        i &= i - 1;
    }
    return res;
}

int main() {
    int q;
    scanf("%d%d", &n, &q);

    for (int i = 1, x; i <= n; ++i) {
        scanf("%d", &x);
        update(i, x);
    }

    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", get(l - 1) ^ get(r));
    }
}
