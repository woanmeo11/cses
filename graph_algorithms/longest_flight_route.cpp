// cses: Longest Flight Route
// tags: topo, dp, dfs
// huycon

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int topo[N], d[N], p[N], m;
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

    for (int i = m - 1; i >= 0; --i) {
        int u = topo[i];
        if (u == 1 || d[u])
            for (int v: g[u])
                if (d[u] + 1 > d[v]) {
                    d[v] = d[u] + 1;
                    p[v] = u;
                }
    }

    if (d[n]) {
        vector <int> path;
        path.push_back(n);
        n = p[n];

        while (n) {
            path.push_back(n);
            n = p[n];
        }

        printf("%d\n", path.size());
        for (int i = path.size() - 1; i >= 0; --i)
            printf("%d ", path[i]);
    }
    else
        puts("IMPOSSIBLE");

}
