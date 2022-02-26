// cses: Fibonacci Numbers
// tags: math, matrix exponentiation
// huycon

#include <bits/stdc++.h>

typedef long long ll;
const ll MOD = 1e9 + 7;

struct matrix {
    ll a[2][2] = { {0, 0}, {0, 0} };
    ll * operator [] (int i) {
        return a[i];
    }
};

matrix mul(matrix a, matrix b) {
    matrix c;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % MOD;
    return c;
}

matrix power(matrix a, ll n) {
    matrix res;
    res[0][0] = res[1][1] = 1;
    while (n) {
        if (n & 1)
            res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

int main() {
    ll n;
    scanf("%lld", &n);
    if (n == 0) {
        putchar('0');
        return 0;
    }
    matrix t, f;
    t[0][0] = t[0][1] = t[1][0] = f[0][0] = 1;
    printf("%lld", mul(power(t, n - 1), f)[0][0]);
}
