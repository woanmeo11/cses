// cses: Game Routes
// tags: topo, dp, dfs
// huycon

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, MOD = 1e9 + 7;

int topo[N], d[N], m;
bool visited[N];
vector <int> g[N];

void dfs(int u) {
    visited[u] = true;
    for (int v: g[u])
        if (!visited[v])
            dfs(v);
    topo[m++] = u;
}

int main() {
    int n;
    scanf("%d%d", &n, &m);

    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
    }

    m = 0;
    for (int u = 1; u <= n; ++u)
        if (!visited[u])
            dfs(u);

    d[1] = 1;
    for (int i = m - 1; i >= 0; --i) {
        int u = topo[i];
        for (int v: g[u])
            d[v] = (d[v] + d[u]) % MOD;
    }

    printf("%d", d[n]);
}
