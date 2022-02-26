// cses: Range Sum Queries II
// tags: bit
// huycon

#include <bits/stdc++.h>

typedef long long ll;
const int N = 2e5 + 5;

int n, x[N];
ll bit[N];

void update(int i, ll v) {
    while (i <= n) {
        bit[i] += v;
        i += i & -i;
    }
}

ll get(int i) {
    ll res = 0;
    while (i > 0) {
        res += bit[i];
        i &= i - 1;
    }
    return res;
}

int main() {
    int q;
    scanf("%d%d", &n, &q);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", x + i);
        update(i, x[i]);
    }

    while (q--) {
        int k, a, b;
        scanf("%d%d%d", &k, &a, &b);
        if (k == 1) {
            update(a, b - x[a]);
            x[a] = b;
        }
        else
            printf("%lld\n", get(b) - get(a - 1));
    }
}
