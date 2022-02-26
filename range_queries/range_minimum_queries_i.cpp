// cses: Range Minimum Queries I
// tags: rmq
// huycon

#include <bits/stdc++.h>
using namespace std;

int rmq[20][200005];

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    for (int i = 1; i <= n; ++i)
        scanf("%d", &rmq[0][i]);

    for (int k = 1; (1 << k) <= n; ++k)
        for (int i = 1; i + (1 << k) - 1 <= n; ++i)
            rmq[k][i] = min(rmq[k - 1][i], rmq[k - 1][i + (1 << (k - 1))]);

    while (q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int k = log2(b - a + 1);
        printf("%d\n", min(rmq[k][a], rmq[k][b - (1 << k) + 1]));
    }
}
