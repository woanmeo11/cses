// cses: Exponentiation
// tags: math
// huycon

#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long a, b, res = 1;
        scanf("%lld%lld", &a, &b);
        while (b) {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        printf("%lld\n", res);
    }
}
