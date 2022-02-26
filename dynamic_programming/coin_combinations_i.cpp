// cses: Coin Combinations I
// tags: dp
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105, MAX_VALUE = 1e6 + 5, MOD = 1e9 + 7;
int c[MAX_N], f[MAX_VALUE];

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i)
        scanf("%d", c + i);

    f[0] = 1;
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j)
            if (c[j] <= i)
                f[i] = (f[i] + f[i - c[j]]) % MOD;
    }


    printf("%d", f[x]);
}
