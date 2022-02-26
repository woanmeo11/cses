// cses: Christmas Party
// tags: math
// huycon

#include <bits/stdc++.h>

const int N = 1e6, MOD = 1e9 + 7;
int d[N + 5];

int main() {
    int n;
    scanf("%d", &n);
    d[0] = 1;
    for (int i = 2; i <= n; ++i)
        d[i] = (i - 1LL) * (d[i - 1] + d[i - 2]) % MOD;
    printf("%d", d[n]);
}
