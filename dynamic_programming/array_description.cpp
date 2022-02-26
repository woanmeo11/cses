// cses: Array Description
// tags: dp
// huycon

#include <bits/stdc++.h>

typedef long long ll;
const int MAX_N = 1e5 + 5, MAX_M = 105, MOD = 1e9 + 7;

ll f[MAX_N][MAX_M];

int main() {
    int n, m, x;
    scanf("%d%d%d", &n, &m, &x);

    if (x)
        f[0][x] = 1;
    else
        for (int j = 1; j <= m; ++j)
            f[0][j] = 1;

    for (int i = 1; i < n; ++i) {
        scanf("%d", &x);
        if (x)
            f[i][x] = (f[i - 1][x] + f[i - 1][x - 1] + f[i - 1][x + 1]) % MOD;
        else
            for (int j = 1; j <= m; ++j)
                f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] + f[i - 1][j + 1]) % MOD;
    }

    ll res = 0;
    for (int j = 1; j <= m; ++j)
        res = (res + f[n - 1][j]) % MOD;

    printf("%lld", res);
}

