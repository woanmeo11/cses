// cses: Exponentiation II
// tags: math
// huycon

#include <bits/stdc++.h>

int power(int a, int n, int m) {
    int res = 1;
    while (n) {
        if (n & 1)
            res = 1LL * res * a % m;
        a = 1LL * a * a % m;
        n >>= 1;
    }
    return res;
}

int main() {
    int t, m = 1e9 + 7;
    scanf("%d", &t);
    while (t--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        printf("%d\n", power(a, power(b, c, m - 1), m));
    }
}
