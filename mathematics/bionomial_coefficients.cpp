// cses: Binomial Coefficients
// tags: math
// huycon

#include <bits/stdc++.h>

typedef long long ll;
const int MAX = 1e6, MOD = 1e9 + 7;

ll f[MAX + 5], invf[MAX + 5];

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
    f[0] = invf[0] = 1;
    for (int i = 1; i <= MAX; ++i) {
        f[i] = f[i - 1] * i % MOD;
        invf[i] = invf[i - 1] * power(i, MOD - 2) % MOD;
    }

    int t, n, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        printf("%lld\n", f[n] * invf[k] % MOD * invf[n - k] % MOD);
    }
}
