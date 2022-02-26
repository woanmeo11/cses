// cses: Distributing Apples
// tags: math
// huycon

#include <bits/stdc++.h>

typedef long long ll;
const int N = 1e6, MOD = 1e9 + 7;

ll f[2*N + 5];

ll power(ll x, int n) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    f[0] = 1;
    for (int i = 1; i < n + m; ++i)
        f[i] = f[i - 1] * i % MOD;

    printf("%lld", f[n + m - 1] * power(f[n - 1] * f[m] % MOD, MOD - 2) % MOD);
}
