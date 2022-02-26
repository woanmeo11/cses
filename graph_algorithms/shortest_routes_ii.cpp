// cses: Shortest Routes II
// tags: floyd
// huycon

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll d[505][505];

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);

    for (int u = 1; u <= n; ++u)
        for (int v = u + 1; v <= n; ++v)
            d[u][v] = d[v][u] = 1e18;

    while (m--) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        d[u][v] = d[v][u] = min(d[u][v], 1LL * c);
    }

    for (int k = 1; k <= n; ++k)
        for (int u = 1; u <= n; ++u)
            for (int v = 1; v <= n; ++v)
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);

    while (q--) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (d[u][v] == 1e18)
            puts("-1");
        else
            printf("%lld\n", d[u][v]);
    }
}

