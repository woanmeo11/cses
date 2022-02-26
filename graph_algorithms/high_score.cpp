// cses: High Score
// tags: bellman-ford
// huycon

#include <bits/stdc++.h>
using namespace std;

const int N = 2505, M = 5005;

long long d[N];
bool s[N], t[N];
vector <int> g[N], h[N];
tuple <int, int, int> e[M];

void dfs(vector <int> near[], bool visited[], int u) {
    visited[u] = true;
    for (int v: near[u])
        if (!visited[v])
            dfs(near, visited, v);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].emplace_back(v);
        h[v].emplace_back(u);
        e[i] = {u, v, w};
    }

    dfs(g, s, 1);
    dfs(h, t, n);

    d[1] = 0;
    for (int i = 2; i <= n; ++i)
        d[i] = -1e18;

    bool changed = false;
    for (int i = 0; i < n; ++i) {
        changed = false;
        for (int j = 0; j < m; ++j) {
            int u, v, w;
            tie(u, v, w) = e[j];
            if (s[u] && t[v] && d[v] < d[u] + w) {
                changed = true;
                d[v] = d[u] + w;
            }
        }
        if (changed == false)
            break;
    }

    if (changed)
        puts("-1");
    else
        printf("%lld", d[n]);
}

