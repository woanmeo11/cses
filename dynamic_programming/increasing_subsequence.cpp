// cses: Increasing Subsequence
// tags: dp
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;
int f[MAX_N];

int main() {
    int n, res = 0;
    scanf("%d", &n);
    for (int x, i = 1; i <= n; ++i) {
        f[i] = 2e9;
        scanf("%d", &x);
        int k = lower_bound(f, f + i + 1, x) - f;
        f[k] = x;
        res = max(res, k);
    }
    printf("%d", res);
}

