// cses: Creating Strings II
// tags: math
// huycon

#include <bits/stdc++.h>

typedef long long ll;
const int N = 1e6, MOD = 1e9 + 7;

ll f[N + 5];
int cnt[26];
char s[N + 5];

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
    scanf("%s", s);
    int n;
    for (n = 0; s[n]; ++n)
        ++cnt[s[n] - 97];

    f[0] = 1;
    for (int i = 1; i <= n; ++i)
        f[i] = f[i - 1] * i % MOD;

    ll res = f[n];
    for (int i = 0; i < 26; ++i)
        if (cnt[i] > 1)
            res = res * power(f[cnt[i]], MOD - 2) % MOD;

    printf("%lld", res);
}
