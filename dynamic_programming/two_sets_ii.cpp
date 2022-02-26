// cses: Two Sets II
// tags: dp
// huycon

#include <bits/stdc++.h>

const int MAX_N = 500, MOD = 1e9 + 7;
int f[MAX_N + 5][MAX_N*(MAX_N + 1)/2 + 5];

int main() {
    int n;
    scanf("%d", &n);
    int sum = n*(n + 1) >> 1;

    if (sum & 1) {
        putchar('0');
        return 0;
    }

    sum >>= 1;
    f[0][0] = 1;
    for (int i = 1; i < n; ++i)
        for (int j = 0; j <= sum; ++j) {
            f[i][j] = f[i - 1][j];
            if (j - i >= 0)
                f[i][j] = (f[i][j] + f[i - 1][j - i]) % MOD;
        }

    printf("%d", f[n - 1][sum]);
}

