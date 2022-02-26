// cses: Minimizing Coins
// tags: dp
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105, MAX_VALUE = 1e6 + 5;
int c[MAX_N], f[MAX_VALUE];

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i)
        scanf("%d", c + i);

    for (int i = 1; i <= x; ++i) {
        f[i] = 1e9;
        for (int j = 0; j < n; ++j)
            if (c[j] <= i)
                f[i] = min(f[i], 1 + f[i - c[j]]);
    }


    printf("%d", f[x] == 1e9 ? -1 : f[x]);
}
