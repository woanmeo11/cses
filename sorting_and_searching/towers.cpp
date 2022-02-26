// cses: Towers
// tags: binary search, dp
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;
int f[MAX_N];

int main() {
    int n, x, res = 0;
    scanf("%d", &n);

    f[0] = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        f[i] = INT_MAX;
        int k = upper_bound(f, f + i + 1, x) - f;
        f[k] = x;
        res = max(res, k);
    }

    printf("%d", res);
}
