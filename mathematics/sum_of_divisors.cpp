// cses: Sum of Divisors
// tags: math
// huycon

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ll n, res = 0;
    scanf("%lld", &n);
    for (ll i = 1, j; i <= n; i = j) {
        ll q = n / i;
        j = n/q + 1;
        ll a = j - i, b = i + j - 1;
        if (a & 1)
            b >>= 1;
        else
            a >>= 1;
        a %= MOD;
        b %= MOD;
        res = (res + q*a%MOD*b) % MOD;
    }
    printf("%lld", res);
}
