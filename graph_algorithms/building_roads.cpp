// cses: Building Roads
// tags: graph, dfs
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

vector <int> near[MAX_N];
int cc[MAX_N];
bool visited[MAX_N];

void dfs(int u) {
    visited[u] = true;
    for (int v: near[u])
        if (!visited[v])
            dfs(v);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        near[u].emplace_back(v);
        near[v].emplace_back(u);
    }

    m = 0;
    for (int u = 1; u <= n; ++u)
        if (!visited[u]) {
            cc[m++] = u;
            dfs(u);
        }

    printf("%d\n", m - 1);
    for (int i = 0; i < m - 1; ++i)
        printf("%d %d\n", cc[i], cc[i + 1]);
}

